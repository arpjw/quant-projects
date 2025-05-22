#include "Asset.hpp"
#include "Option.hpp"
#include "Trader.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

int main() {
    Asset asset(100.0, 0.2);
    Option option(100.0, 1.0, 0.05, 0.25, 0.20, 0.15);
    Trader trader;

    int steps = 50;
    double dt = 1.0 / steps;

    std::ofstream csv("simulation_log.csv");
    csv << "Step,Asset,Option,Delta,Gamma,Theta,PnL\n";

    std::cout << std::fixed << std::setprecision(4);

    for (int t = 0; t < steps; ++t) {
        double S = asset.getPrice();
        double timeLeft = option.getTimeToMaturity();
        double optionPrice = option.price(S, timeLeft);
        double delta = option.delta(S, timeLeft);
        double gamma = option.gamma(S, timeLeft);
        double theta = option.theta(S, timeLeft);

        trader.hedge(delta, S);
        trader.record(optionPrice, S);

        double pnl = trader.getPnL(optionPrice, S);

        csv << t << "," << S << "," << optionPrice << "," << delta
            << "," << gamma << "," << theta << "," << pnl << "\n";

        std::cout << "Step " << t
                  << " | S=" << S
                  << " | Option=" << optionPrice
                  << " | Δ=" << delta
                  << " | Γ=" << gamma
                  << " | Θ=" << theta
                  << " | PnL=" << pnl << "\n";

        asset.advance(dt);
        option.advance(dt);
    }

    csv.close();
    std::cout << "\nSimulation complete. Data saved to simulation_log.csv\n";

    return 0;
}