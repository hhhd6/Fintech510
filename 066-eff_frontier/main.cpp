#include "Assets.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>

int main(int argc, char** argv) {
    if (argc != 3 && argc != 4) {
        std::cerr << "Usage: -r(optional) universe.csv correlation.csv" << std::endl;
        return EXIT_FAILURE;
    }

    // Parse command-line arguments
    bool restricted_mode = false;
    const char* universe_file_name = nullptr;
    const char* correlation_file_name = nullptr;

    if (argc == 4 && std::strcmp(argv[1], "-r") == 0) {
        restricted_mode = true;
        universe_file_name = argv[2];
        correlation_file_name = argv[3];
    } else if (argc == 3) {
        universe_file_name = argv[1];
        correlation_file_name = argv[2];
    } else {
        std::cerr << "Error: Invalid command-line arguments." << std::endl;
        return EXIT_FAILURE;
    }

    // Open input files
    std::ifstream universe_file(universe_file_name);
    if (!universe_file.is_open()) {
        std::cerr << "Error: Failed to open universe file: " << universe_file_name << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream correlation_file(correlation_file_name);
    if (!correlation_file.is_open()) {
        std::cerr << "Error: Failed to open correlation file: " << correlation_file_name << std::endl;
        return EXIT_FAILURE;
    }

    // Process portfolio data
    Portfolio portfolio;
    try {
        portfolio = portfolio.readAll(universe_file, correlation_file);
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "ROR,volatility" << std::endl;
    for (double r = 0.01; r <= 0.27; r += 0.01) {
        try {
            double volatility = portfolio.optimize(r, restricted_mode);
            // Adjust precision for ROR and Volatility
            std::cout << std::fixed << std::setprecision(1) << r * 100 << "%"  // 1 decimal place for ROR
                    << "," 
                      << std::fixed << std::setprecision(2) << volatility * 100 << "%"  // 2 decimal places for volatility
                    << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Optimization error: " << ex.what() << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
