#pragma once

class Option {
private:
    double K, T, r;
    double sigma_ITM, sigma_ATM, sigma_OTM;

public:
    Option(double strike, double maturity, double rate,
           double vol_ITM, double vol_ATM, double vol_OTM);

    double price(double S, double t) const;
    double delta(double S, double t) const;
    double gamma(double S, double t) const;
    double theta(double S, double t) const;

    void advance(double dt);
    double getTimeToMaturity() const;

private:
    double getVolatility(double S) const;
};