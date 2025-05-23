#pragma once
#include <string>

struct Order {
    long order_id;
    std::string side;  // "buy" or "sell"
    double price;
    int quantity;

    Order() = default;
    Order(long id, const std::string& s, double p, int q)
        : order_id(id), side(s), price(p), quantity(q) {}
};