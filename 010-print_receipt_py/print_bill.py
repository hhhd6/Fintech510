def print_receipt(subtotal, tax_rate, tip_rate):
    """
    Calculate tax, tip and total.
    """
    
    tax = subtotal * tax_rate
    tip = subtotal * tip_rate
    total = subtotal + tax + tip
    # return tax, tip, subtotal
    
    print("{:>9} {:>1} {:>9.2f}".format("Subtotal:", "$", subtotal))
    print("{:>9} {:>1} {:>9.2f}".format("Tax:", "$", tax))
    print("{:>9} {:>1} {:>9.2f}".format("Tip:", "$", tip))
    print("{:>21}".format("=" * 10))
    print("{:>9} {:>1} {:>9.2f}".format("Total:", "$", total))
    

    print("Subtotal: $ {:>9.2f}".format(subtotal))
    print("     Tax: $ {:>9.2f}".format(tax))
    print("     Tip: $ {:>9.2f}".format(tip))
    print("{:>21}".format("=" * 10))
    print("   Total: $ {:>9.2f}".format(total))