# Break Encyption

In the last problem, you saw an implementation of a simple "encryption" 
program.  In this problem, you will write a program that breaks that 
encryption --- that is, it will take as input a text file encrypted with 
the program from the previous assignment and print out the key used to 
encrypt it!

Breaking the Caesar Cipher uses a technique called "frequency counting." 
This technique relies on the fact that the distribution of letters in 
the English vocabulary is far from uniform: 'e' is by far the most common
letter (~13%), followed by 't' (9%), and 'a' (8%).  Note that the average 
frequency is 100/26 ~= 4%. 

This frequency distribution means that if you know (or suspect) that a file 
contains English text encrypted with a Caesar Cipher, you can simply count 
the frequency of all letters in it and guess that the letter which occurs 
most often is 'e'.  Once you know which letter is 'e', you can backsolve 
for the key and decrypt the file. In practice, this requires a large enough 
text that "the law of large numbers" applies---and while it is not guaranteed
to work, it typically does.

## Requirements:
 - Your program will take one command line argument: the name of a 
   file to read as input.
 - Your program will then perform frequency counting on the letters in that 
   text file.  Your program should ignore all non-letter characters 
   (those un-modified by the `encrypt.py` program).
 - Your program should use the frequency count information to determine 
   which letter is 'e' and solve for the key.
 - On success, your program should print a single line of output to stdout, 
   which should contain one decimal (base 10) integer (followed by a newline 
   character).  This number should be the encryption key used on the text. 
   It should be in the range [0,26).  That is, the number you print should
   obey 0 <= answer < 26.
 - On failure, your program should print an appropriate message to the console, 
   then exit with 1 as the error code
 - Name your program  `breaker.py`

## Hints:
 - Divide this problem into sub-problems.  You should probably write at 
   least two functions to do this. One of the instructors used three, 
   not including the "main" portion.
 - Think about how you want to represent your data - what data structure 
   is most appropriate?
 - You may find a function you wrote in a previous classwork useful for this
   assignment.  Feel free to use or adapt it.
 - Remember that everything (including characters) with computers are 
   represented by numbers. While in some programming languages (C, C++, Java), 
   we can do math directly on characters, in Python we will first need to 
   convert the character (which is technically a string) to an int value. 
   Look at `encrypt.py` to see an example of doing math on characters.
 - You only need to produce the key, not the decrypted text.
