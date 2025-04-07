#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <numeric>

int main(int argc, char* argv[]) {
    // Validate command line arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " fileName.txt" << std::endl;
        return EXIT_FAILURE;
    }

    // Open the input file
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    // Read temperatures from the file
    std::vector<int> temperatures;
    int temp;
    while (inputFile >> temp) {
        temperatures.push_back(temp);
    }

    inputFile.close();

    // Validate if there are temperatures in the file
    if (temperatures.empty()) {
        std::cerr << "Error: No temperature data found in file." << std::endl;
        return EXIT_FAILURE;
    }

    // Calculate minimum, maximum, and average temperatures
    int minTemp = *std::min_element(temperatures.begin(), temperatures.end());
    int maxTemp = *std::max_element(temperatures.begin(), temperatures.end());
    double avgTemp = std::accumulate(temperatures.begin(), temperatures.end(), 0.0) / temperatures.size();

    // Output results
    std::cout << "Minimum Temperature:    " << minTemp << std::endl;
    std::cout << "Maximum Temperature:   " << maxTemp << std::endl;
    std::cout << "Max Temp as octal:     " << std::oct << maxTemp << std::endl;
    std::cout << "Max Temp as hex:        " << std::hex << maxTemp << std::endl;
    std::cout << "Average Temperature: " << std::fixed << std::setprecision(2) << avgTemp << std::endl;

    return 0;
}
