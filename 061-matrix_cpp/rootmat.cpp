#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
#include <cmath>

int main() {
    int rows, cols;

    if (!(std::cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        std::cerr << "Invalid matrix dimensions\n";
        return 1;
    }

    Eigen::MatrixXd matrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(std::cin >> matrix(i, j))) {
                std::cerr << "Invalid matrix data\n";
                return 1;
            }
        }
    }

    Eigen::MatrixXd rootMatrix = matrix.array().sqrt();

    std::cout << rows << " " << cols << "\n";

    for (int i = 0; i < rows; ++i) {
        // std::cout << " "; 
        for (int j = 0; j < cols; ++j) {
            // if (j > 0) std::cout << " ";
            double value = rootMatrix(i, j);

            if (std::floor(value) == value) {
                std::cout << std::setw(8) << static_cast<int>(value);
            } else {
                std::cout << std::setw(8) << std::fixed << std::setprecision(5) << value;
            }
            // if (std::floor(value) == value) {
            //     // Output integer if value is a whole number
            //     std::cout << static_cast<int>(value);
            // } else {
            //     // Output floating-point number with 5 decimal places
            //     std::cout << std::fixed << std::setprecision(5) << value;
            // }
        }
        std::cout << "\n";
    }

    return 0;
}
