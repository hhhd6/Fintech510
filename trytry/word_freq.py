import sys

frequent_words = {
    'the', 'be', 'to', 'of', 'and', 'a', 'in', 'that', 'have', 'i',
    'it', 'for', 'not', 'on', 'with', 'he', 'as', 'you', 'do', 'at',
    'this', 'but', 'his', 'by', 'from', 'they', 'we', 'say', 'her', 'she',
    'or', 'an', 'will', 'my', 'one', 'all', 'would', 'there', 'their', 'what',
    'so', 'up', 'out', 'if', 'about', 'who', 'get', 'which', 'go', 'me', 'was',
    'had', "him", "his", "is", "were", "said", "are"
}

def compute_word_frequency(file_path):
    word_count = {}
        
    with open(file_path, 'r') as file:
        for line in file:
            line = line.lower()
            words = line.split()
            for word in words:
                # better ways exist to clean "words"
                word = word.replace("!","").replace(".","").replace("?","").replace(",","")
                word_count[word] = word_count.get(word, 0) + 1
    
    return word_count

def remove_stop_words(d):
    for word in frequent_words:
        if word in d:
            del d[word]

def sort_by_frequency(d):
    #return sorted(d,key=d.get,reverse=True)
    return sorted(d, key=lambda x: (-d[x], x))


if __name__ == "__main__":
    #print(sys.argv)
    #print(len(sys.argv))
    
    #file_path = sys.argv[1]
    file_path = "tale_of_two_cities.txt"
    word_freqs = compute_word_frequency(file_path)
    remove_stop_words(word_freqs)
    freq_words = sort_by_frequency(word_freqs)
    print("Number of unique word:{:d}".format(len(word_freqs)))
    for word in freq_words[:15]:
        print("{:10s}:{:6,d}".format(word,word_freqs[word]))
    file_path = '/Users/xinrandu/Documents/fintech510-studentrepository/trytry/tale_of_two_cities.txt'