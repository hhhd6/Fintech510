# Read: Encrypt

1. Create a file `answer.txt`.
2. Execute the code under the instructions (also in`encrypt.py`) by hand as 
   demonstrated with the memory/trace diagrams in class - you'll need to 
   create a diagram.  Write the output in your `answer.txt` file.
   Assume the program is run as
   ```bash
   python3 encrypt.py 5 input.txt
   ```
3. Take a picture of your diagram.
4. Submit both your `answer.txt` file and your diagram (this can be png/jpg/pdf)
   for grading

Additionally, run the program and `diff` the answer against your own to 
ensure you have the correct output.

When your answer is correct, submit `answer.txt`

As a side note, what this program does is perform a 
[Ceaser Cipher](https://en.wikipedia.org/wiki/Caesar_cipher) --- a very
simplistic form of encryption, which (as we will see in the next problem) is 
very easy to break.

```python
import sys
from sys import argv

def encrypt(f, key):
    """Encrypts the contents of the file object (assumed to be ASCII text)"""
    while True:
        c = f.read(1)
        if not c: break     # legal syntax, useful for this situation

        if c.isalpha():
            c = c.lower()
            c = ord(c)
            c -= ord('a')
            c += key
            c %= 26
            c += ord('a')
            c = chr(c)
        print(c,end="")

if __name__ == "__main__":
    if len(argv) != 3:
        print("Usage: python3 encrypt.py key input_file_name")
        sys.exit(1)

    key = 0
    try:
        key = int(argv[1])
        if (key == 0):
            raise ValueError("invalid key: "+argv[1])
    except:
        print("Invalid key: Must be a non-zero integer")
        sys.exit(2)
    
    with open(argv[2]) as f:
        encrypt(f, key)
```