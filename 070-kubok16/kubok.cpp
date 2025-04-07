#include "kubok.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using namespace std;

vector<int> parseLine(const string& line, const string& prefix) {
    // Check if the line starts with the expected prefix
    if (line.rfind(prefix, 0) != 0) {
        throw runtime_error("Error: Missing or invalid '" + prefix + "' line.");
    }

    // Extract the numbers from the line
    string numbers = line.substr(prefix.size());
    vector<int> result;
    stringstream ss(numbers);
    string item;

    // Split the numbers by comma and add them to the result vector
    while (getline(ss, item, ',')) {
        result.push_back(stoi(item));
    }
    return result;
}

void printFormattedGrid(const vector<vector<int>>& grid, const vector<int>& rowSums, const vector<int>& colSums) {
    const int fieldWidth = 3;

    // Print column sums with proper alignment
    cout << std::setw(fieldWidth) << " ";
    for (int colSum : colSums) {
        cout << std::setw(fieldWidth) << colSum;
    }
    cout << endl;

    // Print rows with their respective row sums and grid values
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << std::setw(fieldWidth) << rowSums[i]; // Row sum aligned
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << std::setw(fieldWidth) << grid[i][j]; // Grid values aligned
        }
        cout << endl;
    }
}

bool validateAndParseFile(const string& filename, vector<vector<int>>& grid, vector<int>& rowSums, vector<int>& colSums) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return false;
    }

    string line;

    try {
        if (!getline(inputFile, line)) throw runtime_error("Error: Missing 'column sums' line.");
        colSums = parseLine(line, "column sums: ");
        if (colSums.size() != GRID_SIZE || any_of(colSums.begin(), colSums.end(), [](int sum) { return sum < 10 || sum > 58; })) {
            throw runtime_error("Error: Invalid column sums. Must be 4 numbers between 10 and 58.");
        }

        // Read row sums
        if (!getline(inputFile, line)) throw runtime_error("Error: Missing 'row sums' line.");
        rowSums = parseLine(line, "row sums: ");
        if (rowSums.size() != GRID_SIZE || any_of(rowSums.begin(), rowSums.end(), [](int sum) { return sum < 10 || sum > 58; })) {
            throw runtime_error("Error: Invalid row sums. Must be 4 numbers between 10 and 58.");
        }

        // Read grid label
        if (!getline(inputFile, line) || line != "grid:") {
            throw runtime_error("Error: Missing 'grid:' label.");
        }

        // Read grid rows
        set<int> usedNumbers;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (!getline(inputFile, line)) throw runtime_error("Error: Missing grid row.");
            vector<int> row = parseLine(line, "");
            if (row.size() != GRID_SIZE) throw runtime_error("Error: Each grid row must have exactly 4 numbers.");
            for (int cell : row) {
                if (cell < 0 || cell > 16) {
                    throw runtime_error("Error: Invalid cell value. Must be between 0 and 16.");
                }
                if (cell != 0 && usedNumbers.count(cell)) {
                    throw runtime_error("Error: Duplicate number found in the grid.");
                }
                if (cell != 0) usedNumbers.insert(cell);
            }
            grid.push_back(row);
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return false;
    }

    return true;
}

bool isValid(const vector<vector<int>>& grid, const vector<int>& rowSums, const vector<int>& colSums, const set<int>& usedNumbers, int row, int col, int num) {
    if (usedNumbers.count(num)) return false;

    int temp = grid[row][col];
    const_cast<vector<vector<int>>&>(grid)[row][col] = num;

    int rowSum = 0;
    for (int i = 0; i < GRID_SIZE; i++) rowSum += grid[row][i];
    if (rowSum > rowSums[row]) {
        const_cast<vector<vector<int>>&>(grid)[row][col] = temp;
        return false;
    }

    int colSum = 0;
    for (int i = 0; i < GRID_SIZE; i++) colSum += grid[i][col];
    if (colSum > colSums[col]) {
        const_cast<vector<vector<int>>&>(grid)[row][col] = temp;
        return false;
    }

    const_cast<vector<vector<int>>&>(grid)[row][col] = temp;
    return true;
}

bool solve(vector<vector<int>>& grid, const vector<int>& rowSums, const vector<int>& colSums, set<int>& usedNumbers) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 16; num++) {
                    if (isValid(grid, rowSums, colSums, usedNumbers, row, col, num)) {
                        grid[row][col] = num;
                        usedNumbers.insert(num);

                        if (solve(grid, rowSums, colSums, usedNumbers)) {
                            return true;
                        }

                        grid[row][col] = 0;
                        usedNumbers.erase(num);
                    }
                }
                return false;
            }
        }
    }
    return true;
}
