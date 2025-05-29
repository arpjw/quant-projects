#include "Parser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Trade> Parser::loadCSV(const std::string& filename) {
    std::vector<Trade> trades;
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        Trade trade;
        std::getline(ss, item, ',');
        trade.timestamp = std::stol(item);
        std::getline(ss, item, ',');
        trade.price = std::stod(item);
        std::getline(ss, item, ',');
        trade.size = std::stoi(item);
        trades.push_back(trade);
    }
    return trades;
}
