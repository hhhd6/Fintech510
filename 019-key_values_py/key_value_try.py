import sys
from sys import argv

# import os
# print(os.getcwd())
def read_key_values(filename):
    """
    Reads a key-value delimited file (separated by first =) into a dictionary

    Args:
    filename(str): name of the file to read
    
    Returns:
    dictionary of the read items
    """
    key_values_dict = {}
    with open(filename, 'r') as f:
        for line in f: # search for all line
            if "=" in line:
                key, value = line.split('=', 1)
                key_values_dict[key.strip()] = value.strip()
    return key_values_dict

# result = read_key_values('/Users/xinrandu/Documents/fintech510-studentrepository/019-key_values_py/kvs1.txt')
# print(result)        
    


def create_output_filename(name):
    """
    create the output file name.  Given an input filename such as "input.txt",
    return "input.txt.counts"
    """
    output = name + ".counts"
    return output


def process_key_file(filename, key_values):
    """
    Loads in a key file and produces a dictionary of the count of the values 
    If a key is not found in key_values use "<unknown>"

    Args:
    filename(str): file containing keys to process
    key_values(dict): existing keys to load
    """
    count = {}
    with open(filename,'rt') as f:
        for line in filename:
            key = line.strip()
            if key in key_values:
                count[key] = count.get(key, 0) + 1
            else:
                if "<unknown>" in key_values:
                    count["<unknown>"] += 1
                else:
                    count["<unknown>"] = 0
result = process_key_file('/Users/xinrandu/Documents/fintech510-studentrepository/019-key_values_py/kvs1.txt', 'apple')
print(result)  
                    
# def write_output(filename, counts):
#     """
#     Writes the content of counts to a file specifed by the filename.
#     The output order is by the highest count descending. If two values are
#     equal, arbitrarily choose 1.
#     For each line, the format is
#     key: value

#     Args:
#     filename(str): filename to open and write the output to.
#     counts(dict): existing keys to load   
#     Returns: None 
#     """
    

# def process(args):
#     """
#     Implement your algorithm in this function
#     """
#     # print(args)   #Uncomment if you want to validate/see the command-line arguments
    


# # __name__ == "__main__" and argv explained in the "modules" notebook
# if __name__ == "__main__":
#     if len(argv) < 3:
#         print("Usage: python3 key_value.py file1_name file2_name ...")
#         sys.exit(-1)
#     process(argv)
    