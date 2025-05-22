#include "Trader.hpp"
#include <cmath>
#include <fstream>

Trader::Trader() : cash(0.0), shares(0.0) {}

void Trader::hedge(double targetDelta, double price) {
    double deltaDiff = targetDelta - shares;
    cash -= deltaDiff * price;
    shares += deltaDiff;
}

void Trader::record(double optionVal, double price) {
    double total = cash + shares * price - optionVal;
    pnlLog.push_back(total);
}

double Trader::getPnL(double optionVal, double price) const {
    return cash + shares * price - optionVal;
}

void Trader::logCSV(const std::string& filename) const {
    std::ofstream out(filename);
    out << "Step,Cash,Shares,PnL\n";
    for (size_t i = 0; i < pnlLog.size(); ++i) {
        out << i << ","
            << cash << ","
            << shares << ","
            << pnlLog[i] << "\n";
    }
}