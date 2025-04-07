#include "matrix.hpp"
#include "asset.hpp"
#include "parse.hpp"
#include <iostream>
#include <cmath>

void Asset::calculateROR() {
    // Calculate Rate of Return for each period
    size_t period = n - 1;
    ror.reserve(period);
    
    // Store the first price to avoid repeated array access
    double previousPrice = price[0];
    size_t n = price.size();
    for (size_t i = 1; i < n; ++i) {
        double currentPrice = price[i];
        // Calculate rate of return: (current - previous) / previous
        ror.push_back((currentPrice - previousPrice) / previousPrice);
        previousPrice = currentPrice;
    }
}

void Asset::calculateAvrSigma() {
    // Early return if no rate of return data available
    if (ror.empty()) {
        return;
    }
    
    const size_t count = ror.size();
    
    avr = 0.0;
    for (const double& return_rate : ror) {
        avr += return_rate;
    }
    avr /= count;
    
    // First calculate the sum of squared deviations
    double variance = 0.0;
    for (const double& return_rate : ror) {
        double deviation = return_rate - avr;
        variance += deviation * deviation;
    }
    
    // Calculate standard deviation using n-1 degrees of freedom
    sigma = std::sqrt(variance / (count - 1));
}