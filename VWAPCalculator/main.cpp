#include "VWAPCalculator.hpp"
#include "Parser.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<Trade> trades = Parser::loadCSV("trades.csv");
    double vwap = VWAPCalculator::calculateVWAP(trades);
    std::cout << "VWAP: " << vwap << std::endl;
    return 0;
}
