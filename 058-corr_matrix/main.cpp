#include "matrix.hpp"
#include "asset.hpp"
#include "parse.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <datafile>\n";
        return 1;
    }
    
    try {
        int numAssets;
        Asset* assets = readData(argv[1], numAssets);
        
        // Calculate returns and statistics for each asset
        for (int i = 0; i < numAssets; ++i) {
            assets[i].calculateROR();
            assets[i].calculateAvrSigma();
        }
        
        // Calculate correlation matrix
        DoubleMatrix corrMat = corrMatrix(assets, numAssets);
        
        for (int i = 0; i < numAssets; ++i) {
            std::cout << assets[i].name << std::endl;
        }
        std::cout << corrMat << std::endl;
        
        delete[] assets;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

