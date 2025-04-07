from sys import argv
import sys


def parse_state_information(filename):
    """
    Opens the state information file named in filename, loads all of the 
    values, placing them in a single data structure. Returns that data 
    structure.  You may created nested data structures.
    """
    state_info = []
    with open(filename, 'r') as f:
        for line in f:
            # part = line.strip().split(':')
            # state = part[0]
            # population = int(part[1])
            # electoral_votes = int(part[2])
            # state_info[state] = {'state': state, 'Population': population, 'Electoral Votes': electoral_votes}
            state, population, electoral_votes = line.strip().split(':')
            state_info.append({
                'state': state,
                'population': int(population),
                'electoral_votes': int(electoral_votes)
            })
    return state_info
        

def print_state_information(state_info):
    """
    For the state_info data structure (produced as a result),  
    print all statues in alphabetical order using the string:
    "{}: Population - {:,d}, Electoral Votes: {:d}"
    """
    state_info_sorted = sorted(state_info, key=lambda x: x['state'])  # order state_info in alphabetical
    for state in state_info_sorted:
        print(f"{state['state']}: Population - {state['population']:,d}, Electoral Votes: {state['electoral_votes']:d}")


def parse_vote_information(filename):
    """
    Opens the vote information file and returns the information 
    in a data structure
    """
    vote_info = []
    with open(filename, 'r') as f:
        for line in f:
            state, candidate_a_votes = line.strip().split(':')
            vote_info.append({
                'state': state,
                'candidate_a_votes': int(candidate_a_votes)
            })
    return vote_info


def count_electoral_votes(state_info, vote_info):
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
    candidate_a_electoral_votes = 0
    for state in state_info:
        for vote in vote_info:
            if state['state'] == vote['state'] and vote['candidate_a_votes'] > state['population'] / 2:
                candidate_a_electoral_votes += state['electoral_votes']
    return candidate_a_electoral_votes


def determine_winner(state_info, candidate_a_electoral_votes):
    """
    Determines whether Candidate A or Candidate B won based upon who
    won the majority of the electoral votes. If there is a tie, return None.
    Returns "A", "B", or None    the last one is the value None
    """
    total_votes = sum([state['electoral_votes'] for state in state_info])
    
    return (
        'A' if candidate_a_electoral_votes > total_votes / 2
        else 'B' if candidate_a_electoral_votes < total_votes / 2
        else None
    )


def print_winner(winner_name, number_of_votes):
    """
    Prints the winner.  If Candidate A or B wins, print
    "Candidate {} wins the election with {:d} votes" using the winner_name
    and number of Electoral College votes.

    If neither won the vote, print "It's a tie in the Electoral College."
    """
    if winner_name is not None:
        print(f"Candidate {winner_name} wins the election with {number_of_votes:d} votes")
    else:
        print("It's a tie in the Electoral College.")


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
    recount_list = []
    for state in state_info:
        for vote in vote_info:
            if state['state'] == vote['state']:
                candidate_a_percentage = (vote['candidate_a_votes'] / state['population']) * 100
                if 49.50 <= candidate_a_percentage <= 50.50:
                    recount_list.append(
                        f"{state['state']} requires a recount (Candidate A has "
                        f"{candidate_a_percentage:.2f}% of the vote)"
                    )
    return recount_list


def save_recounts(recount_list):
    """
    saves each entry of the list to a file named "recounts.txt".  The
    entries must be printed in alphabetical order.
    """
    recount_list.sort()
    with open('recounts.txt', 'w') as f:
        for recount in recount_list:
            f.write(recount + '\n')


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
    largest_state = None
    max_percentage = 0
    for state in state_info:
        for vote in vote_info:
            if state['state'] == vote['state']:
                candidate_a_percentage = (vote['candidate_a_votes'] / state['population']) * 100
                if candidate_a_percentage > max_percentage:
                    max_percentage = candidate_a_percentage
                    largest_state = state['state']
    return (f"Candidate A won {largest_state} with {max_percentage:.2f}% of the vote" if largest_state else None)


def process(state_info_filename, voter_info_filename):
    """
    Implements the "Several steps exist for this assignment" section
    """
    state_info = parse_state_information(state_info_filename)
    vote_info = parse_vote_information(voter_info_filename)
    print_state_information(state_info)
    number_of_a_votes = count_electoral_votes(state_info, vote_info)
    winner = determine_winner(state_info, number_of_a_votes)
    number_of_winner_votes = (
        number_of_a_votes
        if winner == 'A'
        else sum([state['electoral_votes'] for state in state_info]) - number_of_a_votes
    )
    print_winner(winner, number_of_winner_votes)
    recount = determine_recounts(state_info, vote_info)
    save_recounts(recount)
    print(determine_largest_win(state_info, vote_info))


if __name__ == "__main__":
    """implement checking command line arguments, call process()"""
    if len(sys.argv) != 3:
        print("Error: Invalid number of arguments.")
        sys.exit(101)
    
    state_info_filename = argv[1]
    voter_info_filename = argv[2]
    
    process(state_info_filename, voter_info_filename)
    
