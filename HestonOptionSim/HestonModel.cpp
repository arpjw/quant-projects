#include "HestonModel.hpp"
#include "CorrelatedRNG.hpp"
#include <cmath>
#include <algorithm>

HestonModel::HestonModel(double S0, double v0, double mu,
                         double kappa, double theta,
                         double sigma_v, double rho)
    : S(S0), v(v0), mu(mu),
      kappa(kappa), theta(theta),
      sigma_v(sigma_v), rho(rho) {}

void HestonModel::advance(double dt) {
    auto [dW1, dW2] = generateCorrelatedNormals(rho);

    v = std::max(v, 0.0); // prevent negative variance

    // Euler discretization
    S *= std::exp((mu - 0.5 * v) * dt + std::sqrt(v * dt) * dW1);
    v += kappa * (theta - v) * dt + sigma_v * std::sqrt(std::max(v, 0.0) * dt) * dW2;
    v = std::max(v, 0.0); // keep v non-negative
}

double HestonModel::getPrice() const {
    return S;
}

double HestonModel::getVariance() const {
    return v;
}