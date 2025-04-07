#include <vector>
#include <string>
#include <Eigen/Dense>

class Asset {
private:
    // Name of the asset, rate of return, standard deviation
    std::string name;
    double ror;
    double sd;

public:
    void setName(const std::string& nm) { name = nm; }
    void setSd(double s) { sd = s; }
    void setRor(double r) { ror = r; }
    double getRor() const { return ror; }
    double getSd() const { return sd; }
};

class Portfolio {
private:
    // List of assets in the portfolio, number of assets, correlation matrix
    std::vector<Asset> assets;
    size_t n_assets;
    Eigen::MatrixXd corrMat;

public:
    // Parse input files, compute covariance matrix, optimize portfolio weights
    Portfolio readAll(std::ifstream& uf, std::ifstream& cf);
    Eigen::MatrixXd getCovMat();
    double optimize(double target_ror, bool restricted);
};

