#include "parse.hpp"
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>

void splitString(std::string& s, std::vector<std::string>& v, std::string& c) {
    size_t pos = 0;
    // Split string by delimiter and store results in vector
    while ((pos = s.find(c)) != std::string::npos) {
        v.push_back(s.substr(0, pos));
        s.erase(0, pos + c.length());
    }
    if (!s.empty()) {
        v.push_back(s);
    }
}

Asset* readData(char* filename, int& num) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file");
    }
    
    std::string line;
    std::getline(file, line);
    
    // Parse header line to get asset names
    std::vector<std::string> headers;
    std::string delimiter = ",";
    splitString(line, headers, delimiter);
    
    num = headers.size() - 1;  // Subtract 1 for date column
    if (num <= 0) {
        throw std::runtime_error("Invalid file format");
    }
    
    // Create and initialize assets
    Asset* assets = new Asset[num];
    for (int i = 0; i < num; ++i) {
        assets[i].name = headers[i + 1];
    }
    
    // Read price data
    int dateCount = 0;
    while (std::getline(file, line)) {
        std::vector<std::string> values;
        splitString(line, values, delimiter);
        
        if (values.size() != static_cast<size_t>(num + 1)) {
            delete[] assets;
            throw std::runtime_error("Inconsistent data format");
        }
        
        // Parse price data for each asset
        for (int i = 0; i < num; ++i) {
            double price;
            if (values[i + 1] == "null" || values[i + 1].empty()) {
                price = dateCount > 0 ? assets[i].price.back() : 0;
            } else {
                price = std::stod(values[i + 1]);
            }
            assets[i].price.push_back(price);
        }
        
        values.clear();
        dateCount++;
    }
    
    // Check for minimum required data points
    if (dateCount < 3) {
        delete[] assets;
        throw std::runtime_error("Insufficient data points");
    }
    
    // Set number of data points for each asset
    for (int i = 0; i < num; ++i) {
        assets[i].n = dateCount;
    }
    
    return assets;
}

double covariance(Asset A, Asset B) {
    if (A.ror.size() != B.ror.size() || A.ror.empty()) {
        return 0;
    }
    
    // Calculate covariance between two return series
    double sum = 0;
    for (size_t i = 0; i < A.ror.size(); ++i) {
        sum += (A.ror[i] - A.avr) * (B.ror[i] - B.avr);
    }
    
    return sum / A.ror.size();
}

double correlation(Asset A, Asset B) {
    if (A.sigma == 0 || B.sigma == 0) {
        return 0;
    }
    // Calculate correlation coefficient using covariance and standard deviations
    return covariance(A, B) / (A.sigma * B.sigma);
}

DoubleMatrix corrMatrix(Asset* A, int num) {
    DoubleMatrix result(num, num);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            result[i][j] = (i == j) ? 1.0 : correlation(A[i], A[j]);
        }
    }
    return result;
}