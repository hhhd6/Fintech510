#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix() : rows(0), cols(0) {}
    
    // Constructor with specified dimensions
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(r, std::vector<T>(c));
    }
    
    // Copy constructor
    Matrix(const Matrix& other) : data(other.data), rows(other.rows), cols(other.cols) {}
    
    // Assignment operator
    Matrix& operator=(const Matrix& rhs) {
        if (this != &rhs) {
            data = rhs.data;
            rows = rhs.rows;
            cols = rhs.cols;
        }
        return *this;
    }
    
    // Get dimensions
    size_t getRows() const { return rows; }
    size_t getColumns() const { return cols; }
    
    // Subscript operator
    const std::vector<T>& operator[](size_t i) const {
        assert(i < rows);
        return data[i];
    }
    
    std::vector<T>& operator[](size_t i) {
        assert(i < rows);
        return data[i];
    }
    
    // Equality operator
    bool operator==(const Matrix& rhs) const {
        return data == rhs.data;
    }
    
    // Addition operator
    Matrix operator+(const Matrix& rhs) const {
        assert(rows == rhs.rows && cols == rhs.cols);
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + rhs[i][j];
            }
        }
        return result;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
    if (m.getRows() == 0) {
        os << "[  ]";
        return os;
    }
    
    os << std::fixed << std::setprecision(4);
    os << "[ ";
    for (size_t i = 0; i < m.getRows(); ++i) {
        if (i > 0) os << "  ";
        for (size_t j = 0; j < m.getColumns(); ++j) {
            if (j > 0) {
                if (m[i][j] >= 0) os << ", ";
                else os << ",";
            }
            os << m[i][j];
        }
        if (i == m.getRows() - 1) {
            os << "]";
        } else {
            os << "\n";
        }
    }
    return os;
}

#endif
