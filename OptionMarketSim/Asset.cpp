#include "Asset.hpp"
#include "Utils.hpp"
#include <cmath>

Asset::Asset(double initPrice, double volatility)
    : price(initPrice), sigma(volatility) {}

void Asset::advance(double dt) {
    double dW = randn() * std::sqrt(dt);
    price *= std::exp(-0.5 * sigma * sigma * dt + sigma * dW);
}

double Asset::getPrice() const {
    return price;
}