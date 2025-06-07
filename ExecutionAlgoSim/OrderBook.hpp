#pragma once
#include "Order.hpp"
#include <vector>
#include <fstream>

class OrderBook {
public:
    OrderBook();
    void executeOrder(const Order& order);
private:
    std::ofstream log;
    int orderIdCounter;
};
