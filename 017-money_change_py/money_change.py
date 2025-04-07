def make_change(amount):
    """
    Based on an amount of money, return a dictionary 
    containing the smallest number of bills and coins that add up to the amount
    """
    denominations = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.25, 0.10, 0.05, 0.01]
    change = {}
    
    for money in denominations:
        count = int(amount // money)
        if count > 0:
            change[money] = count
        amount = round(amount % money, 2)
    
    return change
    
    
def print_change(change):
    """
    print changes in descending order of denomination and their corresponding amount
    """
    for money in sorted(change.keys(), reverse=True):
        print(f"${money:.2f}: {change[money]}")