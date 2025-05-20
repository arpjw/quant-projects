#pragma once
#include "Order.hpp"
#include "Trade.hpp"
#include <queue>
#include <vector>
#include <functional>

class OrderBook {
private:
    std::priority_queue<Order, std::vector<Order>, std::function<bool(Order, Order)>> buyBook;
    std::priority_queue<Order, std::vector<Order>, std::function<bool(Order, Order)>> sellBook;
    std::vector<Trade> trades;

public:
    OrderBook();
    void submitOrder(Order order);
    const std::vector<Trade>& getTrades() const;
};
