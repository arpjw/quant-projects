#pragma once

class HestonModel {
private:
    double S, v;
    double mu, kappa, theta, sigma_v, rho;

public:
    HestonModel(double S0, double v0, double mu,
                double kappa, double theta,
                double sigma_v, double rho);

    void advance(double dt);
    double getPrice() const;
    double getVariance() const;
};