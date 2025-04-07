from salaried_employee import SalariedEmployee
from decimal import Decimal


class CommissionedEmployee(SalariedEmployee):
    """Commissioned Employee"""

    def __init__(self, name, job_title, annual_pay_rate, period_gross_sales):
        super().__init__(name, job_title, annual_pay_rate)
        self.__period_gross_sales = Decimal(period_gross_sales)

    @property
    def employee_type(self):
        return "commissioned"

    def calculate_pay(self):
        base_pay = super().calculate_pay()  # Salaried portion
        commission = self.__period_gross_sales * Decimal("0.05")  # 5% of gross sales
        return base_pay + commission
