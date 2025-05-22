#pragma once

class Asset {
private:
    double price;
    double sigma;

public:
    Asset(double initPrice, double volatility);
    void advance(double dt);
    double getPrice() const;
};