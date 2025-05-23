#pragma once
#include "Event.hpp"
#include <vector>
#include <string>

class Parser {
public:
    static std::vector<Event> loadCSV(const std::string& filename);
};