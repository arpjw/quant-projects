#include "MarketMaker.hpp"

MarketMaker::MarketMaker(std::string name, double spread, int size)
    : id(name), inventory(0), cash(0.0), spread(spread), quoteSize(size) {}

std::pair<Order, Order> MarketMaker::generateQuotes(double midPrice, long ts) {
    Order bid(midPrice - spread / 2, quoteSize, Side::BUY, ts);
    Order ask(midPrice + spread / 2, quoteSize, Side::SELL, ts);
    return {bid, ask};
}

void MarketMaker::handleFill(const Order& order) {
    if (order.side == Side::BUY) {
        inventory += order.quantity;
        cash -= order.price * order.quantity;
    } else {
        inventory -= order.quantity;
        cash += order.price * order.quantity;
    }
}

double MarketMaker::getPnL(double midPrice) const {
    return cash + inventory * midPrice;
}

std::string MarketMaker::getId() const {
    return id;
}