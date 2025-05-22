#include "Utils.hpp"
#include <cmath>

double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

double norm_pdf(double x) {
    static const double inv_sqrt_2pi = 0.3989422804014327;
    return inv_sqrt_2pi * std::exp(-0.5 * x * x);
}

double randn() {
    static std::mt19937 rng(std::random_device{}());
    static std::normal_distribution<> dist(0.0, 1.0);
    return dist(rng);
}