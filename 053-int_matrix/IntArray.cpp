#include "IntArray.hpp"
#include <assert.h>
#include <ostream>

IntArray::IntArray() : data(nullptr), numElements(0) {}
IntArray::IntArray(int n) : data(nullptr), numElements(n) {
    if (n < 0) {
        throw std::invalid_argument("Size cannot be negative");
    }
    data = (n > 0) ? new int[n]() : nullptr;
}

IntArray::IntArray(const IntArray & rhs) : data(nullptr), numElements(rhs.numElements) {
    if (numElements > 0) {
        data = new int[numElements];
        for (int i = 0; i < numElements; ++i) {
            data[i] = rhs.data[i];
        }
    }
}
IntArray::~IntArray() {
    delete[] data;
}

IntArray & IntArray::operator=(const IntArray & rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] data;

    numElements = rhs.numElements;
    data = (numElements > 0) ? new int[numElements] : nullptr;
    for (int i = 0; i < numElements; ++i) {
        data[i] = rhs.data[i];
    }
    return *this;
}
const int & IntArray::operator[](int index) const {
    if (index < 0 || index >= numElements) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}
int & IntArray::operator[](int index) {
    if (index < 0 || index >= numElements) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

int IntArray::size() const {
    return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const {
    if (numElements != rhs.numElements) {
        return false;
    }
    for (int i = 0; i < numElements; ++i) {
        if (data[i] != rhs.data[i]) {
            return false;
        }
    }
    return true;
}

bool IntArray::operator!=(const IntArray & rhs) const {
    return !(*this == rhs);
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs) {
    s << "{";
    for (int i = 0; i < rhs.size(); ++i) {
        s << rhs[i];
        if (i < rhs.size() - 1) {
            s << ", ";
        }
    }
    s << "}";
    return s;
}
