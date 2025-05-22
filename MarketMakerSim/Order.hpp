#pragma once

enum class Side { BUY, SELL };

struct Order {
    double price;
    int quantity;
    Side side;
    long timestamp;

    Order(double price, int qty, Side s, long ts)
        : price(price), quantity(qty), side(s), timestamp(ts) {}
};