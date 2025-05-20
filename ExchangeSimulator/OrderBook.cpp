#include "OrderBook.hpp"
#include <algorithm>

OrderBook::OrderBook()
    : buyBook([](Order a, Order b) {
        return a.price < b.price || (a.price == b.price && a.timestamp > b.timestamp);
    }),
      sellBook([](Order a, Order b) {
        return a.price > b.price || (a.price == b.price && a.timestamp > b.timestamp);
    }) {}

void OrderBook::submitOrder(Order order) {
    if (order.type == OrderType::BUY) {
        while (!sellBook.empty() && order.price >= sellBook.top().price && order.quantity > 0) {
            Order bestSell = sellBook.top(); sellBook.pop();
            int qty = std::min(order.quantity, bestSell.quantity);
            trades.push_back({ order.id, bestSell.id, bestSell.price, qty, order.timestamp });

            if (bestSell.quantity > qty) {
                bestSell.quantity -= qty;
                sellBook.push(bestSell);
            }

            order.quantity -= qty;
        }
        if (order.quantity > 0) buyBook.push(order);
    } else {
        while (!buyBook.empty() && order.price <= buyBook.top().price && order.quantity > 0) {
            Order bestBuy = buyBook.top(); buyBook.pop();
            int qty = std::min(order.quantity, bestBuy.quantity);
            trades.push_back({ bestBuy.id, order.id, bestBuy.price, qty, order.timestamp });

            if (bestBuy.quantity > qty) {
                bestBuy.quantity -= qty;
                buyBook.push(bestBuy);
            }

            order.quantity -= qty;
        }
        if (order.quantity > 0) sellBook.push(order);
    }
}

const std::vector<Trade>& OrderBook::getTrades() const {
    return trades;
}