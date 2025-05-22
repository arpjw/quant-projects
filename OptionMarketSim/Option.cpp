#include "Option.hpp"
#include "Utils.hpp"
#include <cmath>
#include <algorithm>

Option::Option(double strike, double maturity, double rate,
               double vol_ITM, double vol_ATM, double vol_OTM)
    : K(strike), T(maturity), r(rate),
      sigma_ITM(vol_ITM), sigma_ATM(vol_ATM), sigma_OTM(vol_OTM) {}

double Option::getVolatility(double S) const {
    double moneyness = S / K;
    if (moneyness < 0.95) return sigma_ITM;
    else if (moneyness > 1.05) return sigma_OTM;
    else return sigma_ATM;
}

double Option::price(double S, double t) const {
    double tau = T - t;
    if (tau <= 0) return std::max(S - K, 0.0);
    double sigma = getVolatility(S);
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * tau) / (sigma * std::sqrt(tau));
    double d2 = d1 - sigma * std::sqrt(tau);
    return S * norm_cdf(d1) - K * std::exp(-r * tau) * norm_cdf(d2);
}

double Option::delta(double S, double t) const {
    double tau = T - t;
    if (tau <= 0) return (S > K) ? 1.0 : 0.0;
    double sigma = getVolatility(S);
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * tau) / (sigma * std::sqrt(tau));
    return norm_cdf(d1);
}

double Option::gamma(double S, double t) const {
    double tau = T - t;
    if (tau <= 0) return 0.0;
    double sigma = getVolatility(S);
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * tau) / (sigma * std::sqrt(tau));
    return norm_pdf(d1) / (S * sigma * std::sqrt(tau));
}

double Option::theta(double S, double t) const {
    double tau = T - t;
    if (tau <= 0) return 0.0;
    double sigma = getVolatility(S);
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * tau) / (sigma * std::sqrt(tau));
    double d2 = d1 - sigma * std::sqrt(tau);
    return - (S * sigma * norm_pdf(d1)) / (2 * std::sqrt(tau))
           - r * K * std::exp(-r * tau) * norm_cdf(d2);
}

void Option::advance(double dt) {
    T -= dt;
}

double Option::getTimeToMaturity() const {
    return T;
}