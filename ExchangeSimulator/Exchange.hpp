#pragma once
#include "OrderBook.hpp"
#include "Trader.hpp"
#include <vector>

class Exchange {
private:
    OrderBook orderBook;
    std::vector<Trader> traders;
    int nextOrderId;

public:
    Exchange();
    void addTrader(const Trader& trader);
    void simulate(int rounds);
};
