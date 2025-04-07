def compute_average(items):
    """
    Computes the average of list, ignoring any entries that 
    are not numbers (floats or ints)

    Args:
    l(list): list of items to compute the average

    returns:
    average of the numbers in the list
    
    raises:
    ValueError if the argument is not a list or if the list does not contain any numbers
    """
    # TODO: Implement function
    # whether the input is a list
    if not isinstance(items, list):
        raise ValueError('This is not a list.')
    
    # filter out not number elements
    numbers = []
    for non_num in items:
        if isinstance(non_num, (int, float)):
            numbers.append(non_num)
    
    # if no numbers are found
    if not numbers:
        raise ValueError('The list has no numbers.')
    
    # the average
    average = sum(numbers) / len(numbers)
    return average
    
    
