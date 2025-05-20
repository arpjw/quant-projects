#pragma once
#include "Order.hpp"

class Trader {
private:
    std::string traderId;
    int capital;
    int holdings;

public:
    Trader(const std::string& id, int capital = 10000);
    Order generateRandomOrder(int orderId, long timestamp);
    std::string getId() const;
};
