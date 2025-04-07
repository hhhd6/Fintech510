
def reveal_mines(board):
    for a in range(len(board)):
        for b in range(len(board[0])):
            if board[a][b] == SQUARE_HAS_MINE:
                board[a][b] = SQUARE_KNOWN_MINE            

    """
    Change SQUARE_HAS_MINE to SQUARE_KNOWN_MINE for all places on the board
    """

"""
commentary: (REMOVE BEFORE CLASS)
- does it work?  yes
- Where's the docstring?
- are a and b good variable names?
- what does len(board) and len(board[0]) mean?  height/width,   use the existing functions
- talk about code readability and maintainance
  -- for a short class project, who cares???
  -- for professional work, can you undersand this if you come back to it in 6 months? how long does it take?
  
- rewrite code -> talk about comprehension before and after
"""    