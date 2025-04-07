payment = float(input("Enter the periodic payment: "))
num_payments = int(input("Enter the number of payments: "))
periodic_rate = float(input("Enter the annual rate: "))/12

future_value = payment *  ((1+periodic_rate)**num_payments -1)/periodic_rate * (1+periodic_rate)
print("Future value: ${:,.2f}".format(future_value))
