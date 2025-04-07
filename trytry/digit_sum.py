def sum_of_digits(n):
    if n < 10:
        return n
    else:
        current_digits = n % 10
        remaining = sum_of_digits(n // 10)
        return current_digits + remaining
        
number = 5623
sum_digits = sum_of_digits(number)
print("{}:{}".format(number,sum_digits))