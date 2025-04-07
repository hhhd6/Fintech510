#include "IntMatrix.hpp"
#include <stdexcept>
#include <iostream>

IntMatrix::IntMatrix() : numRows(0), numColumns(0), rows(nullptr) {}

IntMatrix::IntMatrix(int r, int c) {
    numRows = r;
    numColumns = c;
    rows = new IntArray * [r];
    for(int i = 0;i < r; i++){
        rows[i] = new IntArray(c);
    }
}

IntMatrix::IntMatrix(const IntMatrix & rhs){
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = new IntArray * [numRows];

    for(int i = 0; i < numRows; i++){
        rows[i] = new IntArray(numColumns);
        *rows[i] = *rhs.rows[i];
    }
}

IntMatrix::~IntMatrix() {
        for (int i = 0; i < numRows; ++i) {
            delete rows[i];
        }
        delete[] rows;
    }

IntMatrix &IntMatrix::operator=(const IntMatrix & rhs) {
    if (this != &rhs) {
        for(int i = 0; i< numRows;i++){
    delete rows[i];
    }
    delete[] rows;
    rows = new IntArray * [rhs.numRows];
    for(int i = 0; i < rhs.numRows; i++){
    rows[i] = new IntArray(rhs.numColumns);
    *rows[i] = *rhs.rows[i];
    }
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    
    }
        return *this;
}
int IntMatrix::getRows() const {
    return numRows;
}
int IntMatrix::getColumns() const {
    return numColumns;
}
const IntArray & IntMatrix::operator[](int index) const {
    if (index < 0 || index >= numRows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return *rows[index];
}
IntArray & IntMatrix::operator[](int index) {
    if (index < 0 || index >= numRows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return *rows[index];
}



bool IntMatrix::operator==(const IntMatrix & rhs) const {
    if (numRows != rhs.numRows || numColumns != rhs.numColumns) {
        return false;
    }
    for (int i = 0; i < numRows; ++i) {
        if (*rows[i] != *rhs.rows[i]) {
            return false;
        }
    }
    return true;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
    if (numRows != rhs.numRows || numColumns != rhs.numColumns) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    IntMatrix result(numRows, numColumns);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            (*result.rows[i])[j] = (*rows[i])[j] + (*rhs.rows[i])[j];
        }
    }
    return result;
}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
    s << "[ ";
    for (int i = 0; i < rhs.getRows(); ++i) {
        s << rhs[i];
        if (i < rhs.getRows() - 1) {
            s << ",\n";
        }
    }
    s << " ]";
    return s;
}
