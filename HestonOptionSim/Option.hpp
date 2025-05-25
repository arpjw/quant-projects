#pragma once

class Option {
private:
    double K, r;

public:
    Option(double strike, double rate);

    double price(double S, double K, double r, double T, double v) const;
    double delta(double S, double K, double r, double T, double v) const;
    double gamma(double S, double K, double r, double T, double v) const;
    double theta(double S, double K, double r, double T, double v) const;
};