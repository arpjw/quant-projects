#include "Parser.hpp"
#include <fstream>
#include <sstream>

std::vector<Trade> Parser::loadCSV(const std::string& filename) {
    std::vector<Trade> trades;
    std::ifstream file(filename);
    std::string line;

    getline(file, line); // skip header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        Trade t;

        getline(ss, item, ','); t.timestamp = std::stol(item);
        getline(ss, item, ','); t.price = std::stod(item);
        getline(ss, item, ','); t.size = std::stoi(item);

        trades.push_back(t);
    }

    return trades;
}