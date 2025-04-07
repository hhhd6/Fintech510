import unittest
from bull_market import find_longest_period


class TestBullMarket(unittest.TestCase):
    
    def test_typical_case(self):
        prices = [5475.25, 5480.40, 5474.00, 5501.23, 5510.30, 5518.42, 5512.41, 5514.92, 5517.76, 5522.44]
        expected = [5474.00, 5501.23, 5510.30, 5518.42]
        self.assertEqual(find_longest_period(prices), expected)

    def test_no_increase(self):
        prices = [5475.25, 5465.30, 5455.10, 5440.00]
        expected = []
        self.assertEqual(find_longest_period(prices), expected)

    def test_single_increase(self):
        prices = [5400.00, 5410.00]
        expected = [5400.00, 5410.00]
        self.assertEqual(find_longest_period(prices), expected)

    def test_type_error(self):
        prices = [5400.00, "invalid", 5410.00]
        with self.assertRaises(TypeError):
            find_longest_period(prices)


if __name__ == '__main__':
    unittest.main()