#include "OrderBook.hpp"
#include <fstream>
#include <sstream>

void OrderBook::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string side, priceStr, sizeStr;
        std::getline(ss, side, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, sizeStr, ',');

        double price = std::stod(priceStr);
        double size = std::stod(sizeStr);

        if (side == "bid") {
            bids[price] += size;
        } else if (side == "ask") {
            asks[price] += size;
        }
    }
}

const std::map<double, double>& OrderBook::getBids() const {
    return bids;
}

const std::map<double, double>& OrderBook::getAsks() const {
    return asks;
}
