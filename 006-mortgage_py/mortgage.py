p = input("What is the amount borrowed?")
r = input("What is the annual interest rate - express this as a decimal such as 0.07 for 7%?")

# place your code here after this line
payment = float(p)
annual_rate = float(r)
periodic_rate = annual_rate / 12
num_payments = int(12 * 30)
A = payment * ((1 + periodic_rate) ** num_payments) * periodic_rate / ((1 + periodic_rate) ** num_payments - 1)

payment_amount = int(A * 100) / 100
print(payment_amount)
