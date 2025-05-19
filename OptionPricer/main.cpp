#include <iostream>
#include <cmath>

using namespace std;

double norm_cdf(double x) {
    return 0.5 * erfc(-x / sqrt(2));
}

double black_scholes_price(
    double S,
    double K,
    double T,
    double r,
    double sigma,
    bool isCall
) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (isCall)
        return S * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
    else
        return K * exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}

int main() {
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;

    double call_price = black_scholes_price(S, K, T, r, sigma, true);
    double put_price = black_scholes_price(S, K, T, r, sigma, false);

    cout << "European Call Option Price: " << call_price << endl;
    cout << "European Put Option Price: " << put_price << endl;

    return 0;
}
