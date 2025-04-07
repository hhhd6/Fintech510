import unittest
from credit_card import validate


class TestCreditCardValidator(unittest.TestCase):
    """
    Tests a credit card number validator
    """

    def test_valid_visa(self):
        """Ensures a valid visa number passes"""
        self.assertTrue(validate("4263982640269299"))

    def test_valid_mastercard(self):
        """Ensures a valid mastercard number passes"""
        self.assertTrue(validate("5425233430109903"))        

    def test_valid_american_express(self):
        """Ensures a valid american express number passes"""
        self.assertTrue(validate("374245455400126")) 

    def test_invalid_american_express(self):
        """Ensure an invalid american express number fails"""
        self.assertFalse(validate("37024907644532"))     
    
    def test_invalid_visa_length(self):
        """Visa card number should be 16 digits"""
        # 14 digits
        self.assertFalse(validate("42639826402692"))
        # 17 digits
        self.assertFalse(validate("42639826402692993")) 
                
    def test_invalid_mastercard_length(self):
        """Mastercard number should be 16 digits"""
        # 15 digits
        self.assertFalse(validate("542523343010996"))
        # 17 digits
        self.assertFalse(validate("54252334301099031"))
    
    def test_invalid_characters(self):
        """Card number must be numeric"""
        self.assertFalse(validate("42639826402abc99"))
        
    def test_invalid_mastercard_start(self):
        """Test boundaries"""
        # Below valid range
        self.assertFalse(validate("5025233430109903"))
        # Above valid range
        self.assertFalse(validate("5625233430109903"))
        # Boundary valid number
        self.assertTrue(validate("5125233430109903"))
        self.assertFalse(validate("2220233430109903"))
        self.assertFalse(validate("2721233430109903"))
        
    def test_invalid_american_express_length(self):
        """American express should have 15 digits"""
        # 14 digits
        self.assertFalse(validate("34424545540012"))
        # 16 digits
        self.assertFalse(validate("3742454554001267"))
        self.assertTrue(validate("374245455400126"))


if __name__ == '__main__':
    unittest.main(argv=['unittest', 'TestCreditCardValidator'], verbosity=2, exit=False)