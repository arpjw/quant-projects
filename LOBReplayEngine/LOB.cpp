#include "LOB.hpp"
#include <iostream>

void LOB::apply(const Event& e) {
    Order order(e.order_id, e.side, e.price, e.quantity);

    if (e.type == "add") {
        book.add(order);
    } else if (e.type == "modify") {
        book.modify(order);
    } else if (e.type == "cancel") {
        book.cancel(e.order_id, e.side);
    } else if (e.type == "execute") {
        book.execute(e.order_id, e.side, e.quantity);
    }
}

void LOB::printTopOfBook() const {
    std::cout << "Best Bid: " << book.bestPrice("buy")
              << " (" << book.totalVolumeAtBest("buy") << ")"
              << "  |  Best Ask: " << book.bestPrice("sell")
              << " (" << book.totalVolumeAtBest("sell") << ")\n";
}