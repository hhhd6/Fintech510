#ifndef PARSE_HPP
#define PARSE_HPP

#include "matrix.hpp"
#include "asset.hpp"
#include <string>
#include <vector>

typedef Matrix<double> DoubleMatrix;

void splitString(std::string& s, std::vector<std::string>& v, std::string& c);
Asset* readData(char* filename, int& num);
double covariance(Asset A, Asset B);
double correlation(Asset A, Asset B);
DoubleMatrix corrMatrix(Asset* A, int num);

#endif