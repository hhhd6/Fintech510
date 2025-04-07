def retirement(start_age, initial_savings, working_info, retired_info):
    """
    Prints the current status of an individual's retirement account.
    The dictionaries both have these fields: 
    "months","contribution","rate_of_return"

    Args:
        start_age (int): At what age (in months) does the individual start
        initial_savings (float): initial savings in dollars
        working_info (dict): information about working
        retired_into (dict): information about retirement

Returns:
None
    """
    
    working_balance = calculate_balance(
        working_info['months'],
        initial_savings,
        working_info['contribution'],
        working_info['rate_of_return'],
        start_age
    )
    
    calculate_balance(
        retired_info['months'],
        working_balance,
        retired_info['contribution'],
        retired_info['rate_of_return'],
        start_age + working_info['months']
    )
    
    
def calculate_balance(months, initial_balance, contribution, rate_of_return, start_age):
    balance = initial_balance
    for month in range(months):
        age_years = (start_age + month) // 12
        age_months = (start_age + month) % 12
        print(f"Age {age_years:3d} month {age_months:2d} you have ${balance:,.2f}")
        balance += balance * rate_of_return + contribution
    return balance

# Working:
#   --------
#    Months: 489
#    Per Month Savings: $1000
#    Rate of Return:  4.5% per year ( 0.045/12 per month) 
#                     [above inflation]
#  Retired:
#  --------
#    Months: 384
#    Per Month Spending: -4000
#    Rate of Return: 1% per year ( 0.01/12 per month) 
#                    [above inflation]
#  Starting conditions:
#  -------------------
#     Age: 327 months (27 years, 3 months)
#     Savings: $21,345


working_info = {
    "months": 489,
    "contribution": 1000,
    "rate_of_return": 0.045 / 12
}

retired_info = {
    "months": 384,
    "contribution": -4000,
    "rate_of_return": 0.01 / 12
}

start_age = 327  
initial_savings = 21345

retirement(start_age, initial_savings, working_info, retired_info)