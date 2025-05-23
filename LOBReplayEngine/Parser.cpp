#include "Parser.hpp"
#include "Event.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Event> Parser::loadCSV(const std::string& filename) {
    std::vector<Event> events;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file " << filename << "\n";
        return events;
    }

    std::string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        std::cout << "Raw line: [" << line << "]\n";  // Debug print

        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string item;
        Event e;

        try {
            getline(ss, item, ','); e.timestamp = std::stol(item);
            getline(ss, item, ','); e.type = item;
            getline(ss, item, ','); e.order_id = std::stol(item);
            getline(ss, item, ','); e.side = item;
            getline(ss, item, ','); e.price = std::stod(item);
            getline(ss, item, ','); e.quantity = std::stoi(item);
        } catch (...) {
            std::cerr << "Warning: Malformed line skipped: " << line << "\n";
            continue;
        }

        events.push_back(e);
    }

    return events;
}