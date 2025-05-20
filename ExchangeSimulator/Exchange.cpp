#include "Exchange.hpp"
#include <iostream>

Exchange::Exchange() : nextOrderId(1) {}

void Exchange::addTrader(const Trader& trader) {
    traders.push_back(trader);
}

void Exchange::simulate(int rounds) {
    for (int i = 0; i < rounds; ++i) {
        for (auto& trader : traders) {
            Order o = trader.generateRandomOrder(nextOrderId++, i);
            orderBook.submitOrder(o);
        }
    }

    const auto& trades = orderBook.getTrades();
    std::cout << "=== Executed Trades ===\n";
    for (const auto& t : trades) {
        std::cout << "BUY#" << t.buyOrderId << " <--> SELL#" << t.sellOrderId
                  << " | Qty: " << t.quantity << " @ $" << t.price << std::endl;
    }
}
