#pragma once
#include <map>
#include <vector>
#include <string>

class OrderBook {
public:
    void loadFromCSV(const std::string& filename);
    const std::map<double, double>& getBids() const;
    const std::map<double, double>& getAsks() const;

private:
    std::map<double, double> bids;
    std::map<double, double> asks;
};
