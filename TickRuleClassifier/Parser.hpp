#pragma once
#include "Trade.hpp"
#include <vector>
#include <string>

class Parser {
public:
    static std::vector<Trade> loadCSV(const std::string& filename);
};