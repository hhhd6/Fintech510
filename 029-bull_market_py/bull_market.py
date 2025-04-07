def find_longest_period(prices):
    """
    find_longest_period returns the longest series of closing prices in
    which the prices continually rose (as determined by the number of days).
    If two more more series have the same number of days, return the first
    series found.
    
    Args:
        l(list): list of daily closing prices

    Returns:
        a list containing the series (e.g., part of the original list) that 
        has the closing stock prices in the order in which they appeared in the 
        original list 

    Raises:
        TypeError if the list contains an item that is not arithmetically 
        compatible with ints and floats
    """
    for i in range(len(prices)):
        if not isinstance(prices[i], (int, float)):
            raise TypeError("List must contain only ints or floats")
    
    if len(prices) <= 1:
        return []
    
    max_period = []
    current_period = []
    
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            if not current_period:
                current_period = [prices[i - 1]]
            current_period.append(prices[i])
        else:
            if len(current_period) > len(max_period):
                max_period = current_period
            current_period = []
            
    if len(current_period) > len(max_period):
        max_period = current_period
        
    return max_period