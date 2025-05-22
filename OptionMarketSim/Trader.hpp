#pragma once
#include <vector>

class Trader {
private:
    double cash;
    double shares;
    std::vector<double> pnlLog;

public:
    Trader();
    void hedge(double targetDelta, double price);
    void record(double optionVal, double price);
    double getPnL(double optionVal, double price) const;
    void logCSV(const std::string& filename) const;
};