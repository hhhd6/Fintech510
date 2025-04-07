from employee import Employee
from decimal import Decimal


class SalariedEmployee(Employee):
    """Salaried Employee"""

    def __init__(self, name, job_title, annual_pay_rate):
        super().__init__(name, job_title)
        self.__annual_pay_rate = Decimal(annual_pay_rate)

    @property
    def employee_type(self):
        return "salaried"

    def calculate_pay(self):
        return self.__annual_pay_rate / Decimal(24)  # Bi-monthly pay (1/24th of annual pay rate)
