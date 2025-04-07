#ifndef KUBOK_HPP
#define KUBOK_HPP

#include <vector>
#include <set>
#include <string>

// Constant definition
const int GRID_SIZE = 4;

// Function declarations
std::vector<int> parseLine(const std::string& line, const std::string& prefix);
void printFormattedGrid(const std::vector<std::vector<int>>& grid, const std::vector<int>& rowSums, const std::vector<int>& colSums);
bool validateAndParseFile(const std::string& filename, std::vector<std::vector<int>>& grid, std::vector<int>& rowSums, std::vector<int>& colSums);
bool isValid(const std::vector<std::vector<int>>& grid, const std::vector<int>& rowSums, const std::vector<int>& colSums, const std::set<int>& usedNumbers, int row, int col, int num);
bool solve(std::vector<std::vector<int>>& grid, const std::vector<int>& rowSums, const std::vector<int>& colSums, std::set<int>& usedNumbers);

#endif
