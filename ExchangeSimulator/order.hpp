#pragma once
#include <string>

enum class OrderType { BUY, SELL };

struct Order {
    int id;
    std::string traderId;
    OrderType type;
    double price;
    int quantity;
    long timestamp;

    Order(int id, std::string traderId, OrderType type, double price, int quantity, long ts)
        : id(id), traderId(traderId), type(type), price(price), quantity(quantity), timestamp(ts) {}
};
