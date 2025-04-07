import sys


def count_fre(f):
    with open(f, 'r') as file:
        content = file.read()
    
    lower_content = content.lower()
    
    if not dict:
        sys.exit(1)
        
    dict_letter = {}
    for char in lower_content:
        if char.isalpha():
            if char in dict_letter:
                dict_letter[char] += 1
            else:
                dict_letter[char] = 1
                
    if not dict_letter:
        sys.exit(1)
        
    dict_letter_sorted = sorted(dict_letter.items(), key=lambda x: x[1], reverse=True)

    if len(dict_letter_sorted) > 1 and dict_letter_sorted[0][1] == dict_letter_sorted[1][1]:
        sys.exit(1)

    most_common_letter = dict_letter_sorted[0][0]
    return most_common_letter


def breaker(most_frequent_letter):
    e_ord = ord('e')
    letter_ord = ord(most_frequent_letter)
    key = (letter_ord - e_ord) % 26
    return key


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 breaker.py input_file_name")
        sys.exit(1)
        
    f = sys.argv[1]
    most_frequent_letter = count_fre(f)
    key = breaker(most_frequent_letter)
    
    print(key)
