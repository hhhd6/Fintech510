def array_max(array):
    """
    Finds the largest number in the list.
    Ignores elements that are not an int or a float

    Args:
        array (list): list of numbers (either float or int)

    Returns:
    Largest number in the list.  None if array is empty
    or if array is not a list.
    """
# Check if the input is a list and if the list is not empty
    if not isinstance(array, list) or len(array) == 0:
        return None

    max_val = None

    for element in array:
        if isinstance(element, (int, float)):
            if max_val is None or element > max_val:
                max_val = element
                
    return max_val