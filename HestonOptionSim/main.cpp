#include "HestonModel.hpp"
#include "Option.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    // Simulation parameters
    double S0 = 100.0;
    double v0 = 0.04;
    double mu = 0.05;
    double kappa = 2.0;
    double theta = 0.04;
    double sigma_v = 0.3;
    double rho = -0.7;

    double T = 1.0;
    int steps = 252;
    double dt = T / steps;

    // Option params
    double K = 100.0;
    double r = 0.01;

    HestonModel model(S0, v0, mu, kappa, theta, sigma_v, rho);
    Option option(K, r);

    std::ofstream log("heston_output.csv");
    log << "Step,Time,Asset,Volatility,OptionPrice,Delta,Gamma,Theta\n";

    std::cout << std::fixed << std::setprecision(4);

    for (int i = 0; i <= steps; ++i) {
        double t = i * dt;
        double S = model.getPrice();
        double v = model.getVariance();
        double opt = option.price(S, K, r, T - t, v);
        double delta = option.delta(S, K, r, T - t, v);
        double gamma = option.gamma(S, K, r, T - t, v);
        double theta = option.theta(S, K, r, T - t, v);

        std::cout << "t=" << t << " | S=" << S << " | v=" << v
                  << " | Price=" << opt << " | Δ=" << delta
                  << " | Γ=" << gamma << " | Θ=" << theta << "\n";

        log << i << "," << t << "," << S << "," << v << ","
            << opt << "," << delta << "," << gamma << "," << theta << "\n";

        model.advance(dt);
    }

    log.close();
    return 0;
}