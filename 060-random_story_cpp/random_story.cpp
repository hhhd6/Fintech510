#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <regex>

using namespace std;

int generate_random_number(int max, int seed) {
    // Usually, we would use "rd" to seed the random number generator
    // in non-test / non-reproducibility situations.
    //
    // Also, we wouldn't recreate the generator every call, but re-use
    // to generate a sequence of results.
    // using class static members would be a good place to hold these objects
    //
    // std::random_device rd;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(0, max); // closed interval
    return distr(gen);
}

map<string, vector<string>> parse_word_categories(const string& file_path) {
    map<string, vector<string>> word_categories;
    ifstream file(file_path);

    if (!file.is_open()) {
        cerr << "Error: Could not open word categories file: " << file_path << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        size_t colon_pos = line.find(':');
        if (colon_pos == string::npos) {
            cerr << "Error: Invalid format in word categories file." << endl;
            exit(1);
        }

        string category = line.substr(0, colon_pos);
        string words = line.substr(colon_pos + 1);

        stringstream word_stream(words);
        string word;
        while (getline(word_stream, word, ',')) {
            word_categories[category].push_back(word);
        }
    }

    file.close();
    return word_categories;
}

string generate_story(const string& template_file, const map<string, vector<string>>& word_categories, int seed) {
    ifstream file(template_file);
    if (!file.is_open()) {
        cerr << "Error: Could not open story template file: " << template_file << endl;
        exit(1);
    }

    stringstream story_output;
    string line;
    regex placeholder_regex("<([a-zA-Z0-9_]+)>");
    smatch match;

    while (getline(file, line)) {
        string processed_line = line;
        auto it = processed_line.begin();
        while (regex_search(processed_line, match, placeholder_regex)) {
            string placeholder = match[1];
            if (word_categories.find(placeholder) == word_categories.end()) {
                cerr << "Error: Placeholder <" << placeholder << "> has no matching category." << endl;
                exit(1);
            }

            const vector<string>& words = word_categories.at(placeholder);
            int random_index = generate_random_number(words.size() - 1, seed);
            string random_word = words[random_index];

            processed_line.replace(match.position(), match.length(), random_word);
            it = processed_line.begin() + match.position() + random_word.size();
        }

        story_output << processed_line << endl;
    }

    file.close();
    return story_output.str();
}

int main(int argc, char *argv[]) {
    // Validate command-line arguments
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <story_template_file> <word_categories_file> <random_seed>" << endl;
        return 1;
    }

    string story_template_file = argv[1];
    string word_categories_file = argv[2];
    int random_seed;
    try {
        random_seed = stoi(argv[3]);
    } catch (const invalid_argument&) {
        cerr << "Error: Random seed must be an integer." << endl;
        return 1;
    }

    // Parse word categories
    map<string, vector<string>> word_categories = parse_word_categories(word_categories_file);

    // Generate and output the story
    string story = generate_story(story_template_file, word_categories, random_seed);
    cout << story;

    return 0;

}

