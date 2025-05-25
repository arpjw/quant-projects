#include "Option.hpp"
#include "Utils.hpp"
#include <cmath>
#include <algorithm>

Option::Option(double strike, double rate)
    : K(strike), r(rate) {}

double Option::price(double S, double K, double r, double T, double v) const {
    if (T <= 0) return std::max(S - K, 0.0);
    double sigma = std::sqrt(v);
    double d1 = (std::log(S / K) + (r + 0.5 * v) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
}

double Option::delta(double S, double K, double r, double T, double v) const {
    if (T <= 0) return (S > K) ? 1.0 : 0.0;
    double sigma = std::sqrt(v);
    double d1 = (std::log(S / K) + (r + 0.5 * v) * T) / (sigma * std::sqrt(T));
    return norm_cdf(d1);
}

double Option::gamma(double S, double K, double r, double T, double v) const {
    if (T <= 0) return 0.0;
    double sigma = std::sqrt(v);
    double d1 = (std::log(S / K) + (r + 0.5 * v) * T) / (sigma * std::sqrt(T));
    return norm_pdf(d1) / (S * sigma * std::sqrt(T));
}

double Option::theta(double S, double K, double r, double T, double v) const {
    if (T <= 0) return 0.0;
    double sigma = std::sqrt(v);
    double d1 = (std::log(S / K) + (r + 0.5 * v) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return - (S * sigma * norm_pdf(d1)) / (2 * std::sqrt(T))
           - r * K * std::exp(-r * T) * norm_cdf(d2);
}