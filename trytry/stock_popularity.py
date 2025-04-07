import sys


"""
Process a csv text file where each row contains a student name, stock ticker,
and number of shares own. Prints a table of the number of students who 
own that stock    
"""


def open_file(filename):
    """
    Opens the given filename return the File object.
    Any errors will halt the program and provide an appropriate message
    to stderr and return a specific exit code

    Args:
        filename (str): name of the file to open

    Returns:
        file object
    """
    try:
        f = open(filename, "rt")
    except FileNotFoundError as fe:
        print("Unable to locate the specified file:", fe.filename, file=sys.stderr)
        exit(2)
    except PermissionError as pe:
        print("You can't access that file: {}".format(pe.filename), file=sys.stderr)
        exit(3)
    except Exception as ex:
        print("Unknown error:", ex, file=sys.stderr)
        print(type(ex), file=sys.stderr)
        exit(4)
    return f


def consume_header(f):
    """
    Reads and validates the expected header from the file.
    If invalid, will halt the program with an appropriate error message and exit code

    Args:
        f (File): File that's processing student records
    """
    header_line = f.readline()    # consume the header row
    if header_line != "student,stock_ticker,num_shares\n":
        print("File missing expected header row: student,stock_ticker,num_shares", file=sys.stderr)
        exit(5)


def process_line(line):
    """
    Validates that the line is in the correct format.  Assumes line is a string

    Args:
        line (str): line in the format of name,ticker,num_shares
    Returns:
        list containing the student name, stock ticker, and number of shares owned
    """
    items = line.strip().split(",")
    if len(items) != 3:
        print("Unexpected number of entries in row (!=3):", line, file=sys.stderr)
        exit(6)
    try:
        number = int(items[2])
    except Exception as ex:
        print("Number of shares owned is not an integer:", items[2], file=sys.stderr)
        exit(7)
        
    if number < 0:
        print("Impossible to own a negative number of shares:",number,file=sys.stderr)
        exit(8)
    
    return items


def read_stock_file(f):
    """
    Reads a csv-delimited file of stock_ownership.  This file must have a
    header row: student,stock_ticker,num_shares

    Args:
    f(file object): opened file to read

    Returns:
    dictionary of the store stocks owned by student
             # key = student name
             # value = list of dictionaries. Each dictionary contains "ticker" and "num_shares"
    """
    
    consume_header(f)

    stocks = {}
    for line in f:
        name, ticker, num_shares = process_line(line)
        student_stocks = stocks.get(name, [])
        student_stocks.append({"ticker": ticker, "num_shares": num_shares})
        stocks[name] = student_stocks

    f.close()       # not validating if this was successful. 

    return stocks


def compute_num_owner_counts(stocks):
    """
    computes the number of students who own a particular stock

    Args:
    stocks(dict): dictionary returned from read_stock_file

    Returns:
    dictionary where the key is a stocker ticker and the value is # of students who own it
    """
    stock_ownership_counts = {}    # key = stock ticker, value = num students owning that stock
    for student in stocks:
        for student_record in stocks[student]:
            ticker = student_record["ticker"]
            stock_ownership_counts[ticker] = stock_ownership_counts.get(ticker, 0) + 1

    return stock_ownership_counts


def display_counts(counts):
    """
    print a table to stdout of the stocks and number of students who own each stock
    sort the output by the number descending

    Args:
        counts (dict): ticker/num of students who own
    """
    popularity_keys = sorted(counts, key=counts.get, reverse=True)
    for ticker in popularity_keys:
        print("{:>5s}:{:3d}".format(ticker, counts[ticker]))


def process(argv):
    f = open_file(argv[1])
    stocks = read_stock_file(f)
    f.close()
    counts = compute_num_owner_counts(stocks)
    display_counts(counts)

 
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 stock_popularity.py data_file")
        sys.exit(-1) 
    process(sys.argv)
