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

    Eigen::MatrixXd squaredMatrix = matrix.array().square();

    std::cout << rows << " " << cols << "\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << " ";
        for (int j = 0; j < cols; ++j) {
            if (j > 0) std::cout << " ";
            std::cout << std::setw(2) << static_cast<int>(squaredMatrix(i, j));
        }
        std::cout << "\n";
    }

    return 0;
}

