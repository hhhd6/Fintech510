#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "StockData.hpp"

std::ifstream openFile(std::string name) { 
    std::ifstream in(name);
    if (!in.is_open()) {
        std::cerr << "Unable to open " << name << std::endl;
        exit(EXIT_FAILURE);  // since we are in function, return would go back to main
    }
    return in;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " stockDataFile\n";
        return EXIT_FAILURE;
    }

    std::ifstream inputFile = openFile(argv[1]);

    std::vector<StockData> data;
    std::string line;

    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        data.push_back(StockData::fromString(line));
    }
    // Insert assignment code

    // Calculate daily returns
    std::vector<double> returns;
    for (size_t i = 1; i < data.size(); ++i) {
        returns.push_back(data[i].rateOfReturn(data[i-1]));
    }
    
    // Calculate average return using accumulate
    double average_return = std::accumulate(returns.begin(), returns.end(), 0.0) / returns.size();
    
    // Find maximum and minimum returns using max_element and min_element
    auto max_return = std::max_element(returns.begin(), returns.end());
    auto min_return = std::min_element(returns.begin(), returns.end());
    
    // Get indices for the dates of max and min returns
    // Add 1 because returns vector starts from second day of data
    size_t max_day_index = std::distance(returns.begin(), max_return) + 1;
    size_t min_day_index = std::distance(returns.begin(), min_return) + 1;
    
    // Output results with formatting
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average Daily Return: " << average_return << "%" << std::endl;
    std::cout << "Largest Gain: " << *max_return << "% on " << data[max_day_index].date << std::endl;
    std::cout << "Largest Loss: " << *min_return << "% on " << data[min_day_index].date << std::endl;

    return EXIT_SUCCESS;
}