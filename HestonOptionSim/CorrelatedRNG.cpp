#include "CorrelatedRNG.hpp"
#include "Utils.hpp"
#include <cmath>

std::pair<double, double> generateCorrelatedNormals(double rho) {
    double z1 = randn();
    double z2 = randn();

    double x = z1;
    double y = rho * z1 + std::sqrt(1 - rho * rho) * z2;

    return {x, y};
}
