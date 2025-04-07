#include "Assets.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <set>

// Ensure the correlation matrix satisfies mathematical constraints
bool validate_correlation_matrix(const Eigen::MatrixXd& matrix) {
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            if (std::abs(matrix(i, j)) > 1 || matrix(i, j) != matrix(j, i) || (i == j && matrix(i, j) != 1)) {
                return false;
            }
        }
    }
    return true;
}

// Split a string by ','
std::vector<std::string> split_line(const std::string& line) {
    std::vector<std::string> result;
    std::istringstream stream(line);
    std::string token;
    while (std::getline(stream, token, ',')) {
        result.push_back(token);
    }
    return result;
}

// Read and validate input files, then populate portfolio
Portfolio Portfolio::readAll(std::ifstream& universe_file, std::ifstream& correlation_file) {
    Portfolio portfolio;
    std::string line;

    // Parse universe.csv
    while (std::getline(universe_file, line)) {
        auto fields = split_line(line);
        if (fields.size() != 3) {
            throw std::runtime_error("Error: Incorrect universe file format. Expected: name,ror,sd.");
        }

        Asset asset;
        // try {
        //     asset.setName(fields[0]);
        //     asset.setRor(std::stod(fields[1]));
        //     asset.setSd(std::stod(fields[2]));
        // } catch (...) {
        //     throw std::runtime_error("Error: Universe data could not be converted to numbers.");
        // }
        // portfolio.assets.push_back(asset);
        asset.setName(fields[0]);
        asset.setRor(std::stod(fields[1]));
        asset.setSd(std::stod(fields[2]));
        portfolio.assets.push_back(asset);
    }
    portfolio.n_assets = portfolio.assets.size();
    if (portfolio.n_assets == 0) {
        throw std::runtime_error("Error: No assets found in universe file.");
    }

    // Parse correlation.csv
    portfolio.corrMat = Eigen::MatrixXd::Zero(portfolio.n_assets, portfolio.n_assets);
    size_t row = 0;

    while (std::getline(correlation_file, line)) {
        auto fields = split_line(line);
        if (fields.size() != portfolio.n_assets) {
            throw std::runtime_error("Error: Incorrect correlation file format. Column count mismatch.");
        }

        for (size_t col = 0; col < fields.size(); ++col) {
            // try {
            //     portfolio.corrMat(row, col) = std::stod(fields[col]);
            // } catch (...) {
            //     throw std::runtime_error("Error: Correlation data could not be converted to numbers.");
            // }
            portfolio.corrMat(row, col) = std::stod(fields[col]);
        }
        ++row;
    }
    if (row != portfolio.n_assets || !validate_correlation_matrix(portfolio.corrMat)) {
        throw std::runtime_error("Error: Correlation matrix is invalid.");
    }

    return portfolio;
}

// Compute the covariance matrix for the portfolio
Eigen::MatrixXd Portfolio::getCovMat() {
    Eigen::MatrixXd covariance_matrix = Eigen::MatrixXd::Zero(n_assets, n_assets);
    for (size_t i = 0; i < n_assets; ++i) {
        for (size_t j = 0; j < n_assets; ++j) {
            covariance_matrix(i, j) = corrMat(i, j) * assets[i].getSd() * assets[j].getSd();
        }
    }
    return covariance_matrix;
}

// Optimize portfolio to minimize volatility
double Portfolio::optimize(double target_ror, bool restricted) {
    auto covariance_matrix = getCovMat();

    // Construct A and b
    Eigen::MatrixXd A(2, n_assets);
    Eigen::VectorXd b(2);
    for (size_t i = 0; i < n_assets; ++i) {
        // Sum of weights = 1
        A(0, i) = 1;
        // Sum of weighted returns = target_ror
        A(1, i) = assets[i].getRor();
    }
    b << 1, target_ror;

    // Construct the left-hand matrix and the right-hand vector
    Eigen::MatrixXd Left(n_assets + 2, n_assets + 2);
    Eigen::VectorXd Right(n_assets + 2);
    
    Left.block(0, 0, n_assets, n_assets) = covariance_matrix;
    Left.block(0, n_assets, n_assets, 2) = A.transpose();
    Left.block(n_assets, 0, 2, n_assets) = A;
    Left.block(n_assets, n_assets, 2, 2) = Eigen::MatrixXd::Zero(2, 2);
    Right.head(n_assets) = Eigen::VectorXd::Zero(n_assets);
    Right.tail(2) = b;

    // Solve the system
    Eigen::VectorXd solution = Left.colPivHouseholderQr().solve(Right);
    Eigen::VectorXd weights = solution.head(n_assets);

    if (restricted) {
        std::set<size_t> zeroed_indices;
        while (true) {
            bool all_positive = true;
            for (size_t i = 0; i < n_assets; ++i) {
                if (weights(i) < 0 && zeroed_indices.find(i) == zeroed_indices.end()) {
                    all_positive = false;
                    zeroed_indices.insert(i);

                    Eigen::MatrixXd tempLeft = Left;
                    Eigen::VectorXd new_constraint = Eigen::VectorXd::Zero(Left.rows());
                    new_constraint(i) = 1;

                    Left.conservativeResize(Left.rows() + 1, Left.cols() + 1);
                    Left.block(0, Left.cols() - 1, Left.rows() - 1, 1) = new_constraint;
                    Left.block(Left.rows() - 1, 0, 1, Left.cols() - 1) = new_constraint.transpose();
                    Left(Left.rows() - 1, Left.cols() - 1) = 0;

                    Right.conservativeResize(Right.size() + 1);
                    Right(Right.size() - 1) = 0;
                }
            }
            if (all_positive) break;
            weights = Left.colPivHouseholderQr().solve(Right).head(n_assets);
        }
    }

    return std::sqrt(weights.transpose() * covariance_matrix * weights);
}

