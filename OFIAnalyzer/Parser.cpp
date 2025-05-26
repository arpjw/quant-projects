#include "Parser.hpp"
#include <fstream>
#include <sstream>

std::vector<Event> Parser::loadCSV(const std::string& filename) {
    std::vector<Event> events;
    std::ifstream file(filename);
    std::string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        Event e;

        getline(ss, item, ','); e.timestamp = std::stol(item);
        getline(ss, item, ','); e.type = item;
        getline(ss, item, ','); e.price = std::stod(item);
        getline(ss, item, ','); e.size = std::stoi(item);
        getline(ss, item, ','); e.side = item;

        events.push_back(e);
    }

    return events;

}