import sys
import pandas as pd
import argparse
from datetime import datetime


# Function to validate the date format
def validate_date_format(date_str):
    try:
        date_str = str(date_str)
        # Try converting the string into a datetime object
        datetime.strptime(date_str, "%Y.%m")
        return True
    except ValueError:
        return False


# to validate the contents of a DataFrame for a specific file type
def validate_data(df, expected_columns, file_type):
    
    # Check whether the header matches the expected columns
    if list(df.columns) != expected_columns:
        print(f"Error: {file_type} data file has incorrect header")
        sys.exit(20 if file_type == 'S&P' else 30)
        
    for i, row in df.iterrows():
        # the number of fields matches the expected number of columns
        if len(row) != len(expected_columns):
            print(f"Error: {file_type} data file has incorrect number of fields on line {i + 2}")
            sys.exit(20 if file_type == 'S&P' else 30)
            
        # Validate date format
        if not validate_date_format(row['Date']):
            print(f"Error: {file_type} data file has an invalid date format on line {i + 2}")
            sys.exit(20 if file_type == 'S&P' else 30)
            
        # Validate numeric fields (should be non-negative)
        try:
            for col in expected_columns[1:]:  # Skip 'Date' column
                value = float(row[col])
                if value < 0:
                    print(f"Error: {file_type} data file has a negative value in '{col}' on line {i + 2}")
                    sys.exit(20 if file_type == 'S&P' else 30)
        except ValueError:
            print(f"Error: {file_type} data file has invalid numeric value on line {i + 2}")
            sys.exit(20 if file_type == 'S&P' else 30)


# read the S&P 500 data from a CSV file
def read_sp_data(file_path):
    
    try:
        # Read the CSV file into a DataFrame
        df = pd.read_csv(file_path)
        
        # Validate the DataFrame for correct structure
        validate_data(df, ['Date', 'Index level', 'Dividend'], 'S&P')
        
        # Convert 'Date' column to string ensuring format
        df['Date'] = df['Date'].astype(str)
        df['Date'] = df['Date'].apply(lambda x: x if len(x.split('.')[1]) == 2 else f"{x.split('.')[0]}.10")
        
        # Convert 'Date' to datetime format
        df['Date'] = pd.to_datetime(df['Date'], format='%Y.%m')
        # df['Date'] = df['Date'].dt.strftime('%Y-%m')
        
        return df
    
    except FileNotFoundError:
        print("Error: S&P data file not found")
        sys.exit(20)
    except Exception as e:
        print(f"Error while reading S&P data file: {e}")
        sys.exit(20)


def read_bond_data(file_path):
    
    try:
        df = pd.read_csv(file_path)
        validate_data(df, ['Date', 'PercentageRate'], 'Bond')
        
        df['Date'] = df['Date'].astype(str)
        df['Date'] = df['Date'].apply(lambda x: x if len(x.split('.')[1]) == 2 else f"{x.split('.')[0]}.10")
        
        df['Date'] = pd.to_datetime(df['Date'], format='%Y.%m')
        # df['Date'] = df['Date'].dt.strftime('%Y-%m')
        
        return df
    
    except FileNotFoundError:
        print("Error: Bond data file not found")
        sys.exit(30)
    except Exception as e:
        print(f"Error while reading Bond data file: {e}")
        sys.exit(30)


def calculate_portfolio_equities(df, initial_balance, monthly_contribution, start_date, end_date):
    
    df_filtered = df[(df['Date'] >= start_date) & (df['Date'] <= end_date)]
    
    balances = []
    balance = initial_balance
    
    for i in range(0, len(df_filtered)):
        current_month = df_filtered['Date'].iloc[i].month
        if current_month == 1:
            monthly_contribution *= 1.025
            
        sp_ror = df_filtered['Index level'].iloc[i] / df_filtered['Index level'].iloc[i - 1] - 1
        
        div_ror = (df_filtered['Dividend'].iloc[i] / 12) / df_filtered['Index level'].iloc[i]
        
        total_ror = sp_ror + div_ror
        
        balance = balance * (1 + total_ror) + monthly_contribution
        
        balances.append(float(balance))

    return balances


def calculate_lifecycle_investment(df_sp, df_bond, initial_balance, monthly_contribution, start_date, end_date):
    
    df_sp_filtered = df_sp[(df_sp['Date'] >= start_date) & (df_sp['Date'] <= end_date)]
    df_bond_filtered = df_bond[(df_bond['Date'] >= start_date) & (df_bond['Date'] <= end_date)]
    
    balances = []
    balance = initial_balance
    lifecycle_allocation = 1.0
    
    for i in range(0, len(df_sp_filtered)):
        current_month = df_sp_filtered['Date'].iloc[i].month
        # current_year = df_sp_filtered['Date'].iloc[i].year
        
        if current_month == 1 and i > 0:
            monthly_contribution *= 1.025
            lifecycle_allocation = max(0.0, lifecycle_allocation - 0.02)
            
        if i > 0:
            sp_ror = df_sp_filtered['Index level'].iloc[i] / df_sp_filtered['Index level'].iloc[i - 1] - 1
            div_ror = (df_sp_filtered['Dividend'].iloc[i] / 12) / df_sp_filtered['Index level'].iloc[i]
            portfolio_ror = sp_ror + div_ror
        else:
            portfolio_ror = 0
            
        bond_rate_yearly = df_bond_filtered['PercentageRate'].iloc[i]
        bond_ror = bond_rate_yearly / 12 / 100
        
        balance = (
            balance * (1 + portfolio_ror) * lifecycle_allocation
            + balance * (1 + bond_ror) * (1 - lifecycle_allocation) + monthly_contribution
        )
        
        balances.append(balance)

    return balances


def calculate_portfolio_bonds(df, initial_balance, monthly_contribution, start_date, end_date):
    
    df_filtered = df[(df['Date'] >= start_date) & (df['Date'] <= end_date)]
    
    balances = []
    balance = initial_balance
    
    for i in range(0, len(df_filtered)):
        
        current_month = df_filtered['Date'].iloc[i].month
        if current_month == 1:
            monthly_contribution *= 1.025
            
        bond_rate_yearly = df_filtered['PercentageRate'].iloc[i]
        bond_ror_monthly = bond_rate_yearly / 12 / 100
        
        balance = balance * (1 + bond_ror_monthly) + monthly_contribution
        
        balances.append(float(balance))

    return balances


def write_to_csv(sp_file, bond_file, start_date, end_date, filename):
    start_date = pd.to_datetime(start_date, format='%Y.%m')
    end_date = pd.to_datetime(end_date, format='%Y.%m')
    
    initial_balance = 0.0
    monthly_contribution = 100.0
    
    df_sp = read_sp_data(sp_file)
    df_bond = read_bond_data(bond_file)
    
    balances_strategy_one = calculate_portfolio_equities(
        df_sp, initial_balance, monthly_contribution, start_date, end_date
    )
    
    balances_strategy_two = calculate_portfolio_bonds(
        df_bond, initial_balance, monthly_contribution, start_date, end_date
    )
    
    balances_strategy_three = calculate_lifecycle_investment(
        df_sp, df_bond, initial_balance, monthly_contribution, start_date, end_date
    )
    
    dates = pd.date_range(start=start_date, end=end_date, freq='MS')
    
    min_length = min(len(balances_strategy_one), len(balances_strategy_two), len(balances_strategy_three), len(dates))
    
    dates = dates[:min_length]
    balances_strategy_one = balances_strategy_one[:min_length]
    balances_strategy_two = balances_strategy_two[:min_length]
    balances_strategy_three = balances_strategy_three[:min_length]
    
    df_results = pd.DataFrame({
        'Date': dates,
        'StrategyOne': balances_strategy_one,
        'StrategyTwo': balances_strategy_two,
        'StrategyThree': balances_strategy_three
    })
    
    df_results['Date'] = df_results['Date'].dt.strftime('%Y.%m')
    
    print(df_results)
    
    df_results.to_csv(
        filename,
        index=False,
        float_format="%.2f",
        header=["Date", "StrategyOne", "StrategyTwo", "StrategyThree"]
    )
    print(f"results have saved in {filename}")


def validate_command_line_args(start_date, end_date):
    
    if not validate_date_format(start_date) or not validate_date_format(end_date):
        print("Error: Date format is invalid. Expected format: YYYY.MM")
        sys.exit(10)
        
    # Check that end_date is on or after start_date
    start_dt = datetime.strptime(start_date, "%Y.%m")
    end_dt = datetime.strptime(end_date, "%Y.%m")
    
    if end_dt < start_dt:
        print("Error: End date must be after or the same as the start date")
        sys.exit(10)


def parse_args():
    parser = argparse.ArgumentParser(description='Retirement Investment Calculator')
    parser.add_argument('sp_file', type=str, help='S&P 500 data file (CSV)')
    parser.add_argument('bond_file', type=str, help='Bond data file (CSV)')
    parser.add_argument('start_date', type=str, help='Start date (format: YYYY.MM)')
    parser.add_argument('end_date', type=str, help='End date (format: YYYY.MM)')
    
    if len(sys.argv) != 5:
        print(f"Error: Expected 4 arguments but got {len(sys.argv) - 1}.")
        parser.print_help()
        sys.exit(1)
        # parser.error("This script requires exactly 4 arguments: sp_file, bond_file, start_date, end_date")
        
    try:
        args = parser.parse_args()
        return args
        
    except argparse.ArgumentError as e:
        print(f"Error with command-line arguments: {e}")
        sys.exit(10)


if __name__ == '__main__':
    args = parse_args()
    validate_command_line_args(args.start_date, args.end_date)
    write_to_csv(args.sp_file, args.bond_file, args.start_date, args.end_date, "portfolio.csv")