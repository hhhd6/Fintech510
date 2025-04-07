#include "kubok.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return EXIT_FAILURE;
    }

    vector<vector<int>> grid;
    vector<int> rowSums;
    vector<int> colSums;

    // Validate and parse the input file
    if (!validateAndParseFile(argv[1], grid, rowSums, colSums)) {
        return EXIT_FAILURE;
    }

    set<int> usedNumbers;
    // Collect the used numbers from the initial grid
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell != 0) {
                usedNumbers.insert(cell);
            }
        }
    }

    if (solve(grid, rowSums, colSums, usedNumbers)) {
        printFormattedGrid(grid, rowSums, colSums);
    } else {
        cerr << "No solution exists for the given puzzle." << endl;
        return EXIT_FAILURE;
    }

    return 0;
}
