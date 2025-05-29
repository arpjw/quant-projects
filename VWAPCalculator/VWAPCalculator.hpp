#pragma once
#include "Trade.hpp"
#include <vector>

class VWAPCalculator {
public:
    static double calculateVWAP(const std::vector<Trade>& trades);
};
