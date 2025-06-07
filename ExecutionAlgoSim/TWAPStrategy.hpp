#pragma once
#include "OrderBook.hpp"

class TWAPStrategy {
public:
    TWAPStrategy(OrderBook& book, int totalQty, int steps);
    void execute();
private:
    OrderBook& orderBook;
    int totalQuantity;
    int totalSteps;
};
