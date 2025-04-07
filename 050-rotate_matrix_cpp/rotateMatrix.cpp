#include <iostream>
#include <fstream>
#include <array>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return EXIT_FAILURE;
    }
    
    std::array<std::array<char, 10>, 10> matrix;
    std::string line;
    int lineCount = 0;

    while (std::getline(file, line)) {
        if (line.length() != 10) {
            std::cerr << "Error: Each line must have exactly 10 characters" << std::endl;
            return EXIT_FAILURE;
        }
        
        if (lineCount >= 10) {
            std::cerr << "Error: The file must contain exactly 10 lines" << std::endl;
            return EXIT_FAILURE;
        }
        
        for (int j = 0; j < 10; ++j) {
            matrix[lineCount][j] = line[j];
        }
        lineCount++;
    }

    if (lineCount != 10) {
        std::cerr << "Error: The file must contain exactly 10 lines" << std::endl;
        return EXIT_FAILURE;
    }

    std::array<std::array<char, 10>, 10> rotatedMatrix;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            rotatedMatrix[j][9 - i] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << rotatedMatrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
