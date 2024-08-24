# Election Evaluative Assignment

In this assignment, you will be writing a program to process 
"election results" (in quotation marks because they aren't real).

As an evaluative assignment, your work must be your own. You submission
of the assignment implies you have read and followed the assignment
rules at the bottom of this page.

Several steps exist for this assignment:
1. Load and process a state information file
2. Print state information
3. Load and process the vote information file
4. Determine who won the election
5. Prints the winner to the console
6. Determine which states require a recount
7. Saves the recount information to a file
8. Determine in which state, candidate A had the largest win
9. Prints the largest win to the console. If candidate A did not have a qualifying win, print "No win"

## State Information File
Before you start, take a look at `US_States.txt`.  This file contains
51 lines (one for each US State, plus the District of Columbia),
describing the population and number of electoral votes the state
receives in the presidential election.

For example, the first line is:
```
Alabama:4858979:9
------- ------- -
  \        \     \  Number of electoral votes for this state
   \        \     -------------------------------------------
    \        \ Population of this state in July 2015
     \        ---------------------------------------
      \  State's name
       ---------------
```
If you look through the rest of the file, you will see that each line
contains the same format.

There is also a simpler file `Simple_States.txt` with four "states" to
help you test (so it is easier to figure out the right answer).

## Vote Information File
Next take a look at `USVotes1.txt`.  This fie contains 51 lines (again,
one for each US State, plus the District of Columbia), describing the
number of votes Candidate A received for the election.  We assume there 
are only two candidates: A and B for each state. There is no guarantee
that the ordering of the state's match the first file.  However, the 
state names will all be present and match the first file exactly.
```
Alabama:1977604
------- -------
 \        \  Number of votes candidate a received
  \        --------------------------------------
   \  State's name
    ---------------
```
As with `Simple_States.txt`, there is a simpler version with just 4 states:
`SimpleVotes1.txt`


## Functions to write
```python
def parse_state_information(filename):
    """
    Opens the state information file named in filename, loads all of the 
    values, placing them in a single data structure. Returns that data 
    structure.  You may create nested data structures.
    """

def print_state_information(state_info):
    """
    For the state_info data structure (produced as a result),  
    print all states in alphabetical order using the string:
    "{}: Population - {:,d}, Electoral Votes: {:d}"
    """

def parse_vote_information(filename):
    """
    Opens the vote information file and returns the information 
    in a data structure
    """

def count_electoral_votes(state_info,vote_info):
    """
    Counts and returns the number of electoral votes received by 
    Candidate A in the election.

    For our purposes, Candidate A receives ALL electoral votes for a
    state if Candidate A receives strictly more than 50% of the votes in
    that State.  [Yes, we know that in the US there are a few states
    with more complex rules, but we will ignore them.  We will also
    ignore the electoral complexities of what would happen if a
    candidate received exactly 50%, and in this case, just say that
    Candidate A does not receive those electoral votes.  We are also
    assuming everyone in every state votes--while this doesn't happen in
    a real election, it is what we are doing here].
    """

def determine_winner(state_info, candidate_a_electoral_votes):
    """
    Determines whether Candidate A or Candidate B won based upon who
    won the majority of the electoral votes. If there is a tie, return None.
    Returns "A", "B", or None (the value None, not the string "None").
    """

def print_winner(winner_name, number_of_votes):
    """
    Prints the winner.  If Candidate A or B wins, print
    "Candidate {} wins the election with {:d} votes" using the winner_name
    and number of Electoral College votes.

    If neither won the vote, print "It's a tie in the Electoral College."
    """

def determine_recounts(state_info, vote_info):
    """
    Produces a list of strings, where each string represents information
    about a state the requires a recount. Recounts are required when a 
    Candidate A is within +/ 0.5% of 50% of the votes.  So 49.50% or 50.50%
    require a recount, while 49.49% and 50.51% do not require a recount.
    
    Only include states that require a recount in the result. For each state
    that requires a recount, include a line of the form:
    "{} requires a recount (Candidate A has {:.2f}% of the vote)".
    """

def save_recounts(recount_list):
    """
    saves each entry of the list to a file named "recounts.txt".  The
    entries must be printed in alphabetical order.
    """

def determine_largest_win(state_info, vote_info):
    """
    Determines in which state Candidate A won the largest percentage 
    of the vote.

    returns a string with the following format:
    "Candidate A won {} with {:.2f}% of the vote"

    where the first {} should be the name of the state, and the {.2f} 
    should be the percentage of the vote won.  For example, it might return
    "Candidate A won California with 73.24% of the vote"

    None is returned if candidate A did not win a state
    """

def process(state_info_filename, voter_info_filename):
    """
    Implements the "Several steps exist for this assignment" section
    """
```

## Main Section
You should also include a "main section" that validates the number of 
command-line arguments.  If the number is wrong, print an error message
and exit with the value of 101.  Then call 
    `process(state_info_filename, voter_info_filename)`

When you are satisfied with your testing, commit, push, and submit your 
assignment for grading.  Your work should be in `election.py`.

Don't try to complete all of this at once.  Get small pieces of the 
code working and validated, then continue to add more functionality.

Unlike previous assignments, you will not receive the complete score
until after the assignment deadline (which is a hard deadline, with any
late assignments receiving a maximum score of 70%).

The "pregrader" tests the provided files and is worth 75% of the grade.

## Assignment Rules

- Your work must be your own!
- You may NOT consult with other students about:
  - high level approaches,
  - how to implement your algorithm in code, or
  - how to debug your code.
  
  Basically, you may not discuss anything particular to this assignment.

- You may NOT look at another student's code, nor show your code to
  anyone else.
- You are responsible for keeping your code private.
- You may not look for solutions to this or similar problems online.
- You may not use code from any other source.
- You may not use any AI assistive technology, including Qubit.

- You MAY consult any of the course Jupyter notebooks
- You MAY consult any Python book on the O'Reilly Learning Platform
- You MAY consult any Python documentation on https://www.python.org/doc/
- You MAY consult notes you wrote in your notebook.
- You MAY consult the man pages.
- You MAY ask the professor or TAs for clarification on the assignment.
