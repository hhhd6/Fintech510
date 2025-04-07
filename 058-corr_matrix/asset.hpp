#ifndef ASSET_HPP
#define ASSET_HPP

#include <string>
#include <vector>

class Asset {
private:
    std::string assetName;
    
public:
    std::vector<double> price;
    std::vector<double> ror;
    double avr;
    double sigma;
    int n;
    std::string name;
    
    Asset() : avr(0), sigma(0), n(0) {}
    
    // the rate of return series
    void calculateROR();
    // average return and standard deviation
    void calculateAvrSigma();
};

#endif
