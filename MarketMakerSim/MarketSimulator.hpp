#pragma once
#include "MarketMaker.hpp"
#include <vector>
#include <memory>

class MarketSimulator {
private:
    std::vector<std::shared_ptr<MarketMaker>> bots;
    double midPrice;

public:
    MarketSimulator(std::vector<std::shared_ptr<MarketMaker>> bots);
    void run(int steps);
};