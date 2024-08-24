# Closed Box Testing

For closed box testing, we do not have any access to the underlying source 
code - we need to consider the test cases solely based upon the inputs and 
the corresponding outputs. To help find appropriate test cases, we examined 
two techniques: boundary value analysis and equivalence partitioning.

You will need to write a series of unit tests to test a credit card number 
validator.  This function has the following definition:
```python
def validate(card_number):
    """
    Validates whether or not a card_number represents a potentially valid
    credit card number.
    Card numbers must be strings composed of ASCII numbers (0-9) meeting these
    rules:
      - Visa cards: starts with the digit 4, length 16
      - Mastercard: starts with 51-55  and 2221-2720, length 16
      - American Express:  starts with 34 or 37, length 15
      - Number must pass the Luhn checksum
    Args:
    card_number(str): credit card number to validate
    returns:
    True if the card_number is valid, False if the car_number is not valid
```
Your task is to create a series of tests that attempt to reveal defects in the
implementation. As this is closed box testing, you will not have access to the 
source so you must apply *boundary value analysis* and *equivalence partitioning* 
to discover the six defects placed into the implementation.

Start by determining the boundaries and equivalence classes in the rules. Use
that data to guide the test you create.

Assume that the following items are correct:
- card_number only contains the character 0-9
- Luhn checksum works correctly.

You will need to write your unit tests in a class called 
`TestCreditCardValidator` placed in a file `credit_card_test.py`.

We have included a templated file with some initial tests for you and a 
correct implementation of the function so you can test locally.

Submit your file to Gradescope for evaluation.

Points awarded: 
- 50 points for the first defect found
- 25 points for each additional defect found
- Maximum score: 100 points 
- Technically, six flaws exist; find at least three for full credit.

You should submit all your tests, even the ones that do not find bugs. 
Remember, you are practicing writing a testing suite, which can be used to 
test the code again as changes are made. There may be a situation where a 
previously passing test fails when someone updates the validate function.
