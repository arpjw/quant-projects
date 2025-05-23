#pragma once
#include "Order.hpp"
#include <map>

class BookSide {
private:
    std::map<double, std::map<long, Order>, std::greater<>> bids;
    std::map<double, std::map<long, Order>> asks;

public:
    void add(const Order& order);
    void modify(const Order& order);
    void cancel(long order_id, const std::string& side);
    void execute(long order_id, const std::string& side, int quantity);
    double bestPrice(const std::string& side) const;
    int totalVolumeAtBest(const std::string& side) const;
};