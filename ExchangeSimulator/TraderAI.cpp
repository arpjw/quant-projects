#include "Trader.hpp"
#include <cstdlib>

Trader::Trader(const std::string& id, int cap) : traderId(id), capital(cap), holdings(0) {}

Order Trader::generateRandomOrder(int orderId, long ts) {
    OrderType type = (rand() % 2 == 0) ? OrderType::BUY : OrderType::SELL;
    double price = 95 + (rand() % 11);  // Random price: 95–105
    int qty = (rand() % 5 + 1) * 10;     // 10, 20, ..., 50

    return Order(orderId, traderId, type, price, qty, ts);
}

std::string Trader::getId() const { return traderId; }
