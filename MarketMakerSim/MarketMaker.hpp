#pragma once
#include "Order.hpp"
#include <string>
#include <utility>

class MarketMaker {
private:
    std::string id;
    int inventory;
    double cash;
    double spread;
    int quoteSize;

public:
    MarketMaker(std::string name, double spread = 1.0, int size = 10);
    std::pair<Order, Order> generateQuotes(double midPrice, long timestamp);
    void handleFill(const Order& order);
    double getPnL(double midPrice) const;
    std::string getId() const;
};