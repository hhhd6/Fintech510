employee_work_hours = float(input("How many hours did the employee work?"))
employee_pay_rate = float(input("What is the employee's pay rate?"))

if employee_work_hours > 40:
    total_pay = 1.5 * employee_pay_rate * (employee_work_hours - 40) + employee_pay_rate * 40
else:
    total_pay = employee_pay_rate * employee_work_hours

taxes = 0.2 * total_pay
net_pay = total_pay - taxes

print("Total pay:", total_pay)
print("Taxes:", taxes)
print("Net pay:", net_pay)