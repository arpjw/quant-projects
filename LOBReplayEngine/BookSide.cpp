#include "BookSide.hpp"

void BookSide::add(const Order& order) {
    if (order.side == "buy") {
        bids[order.price][order.order_id] = order;
    } else {
        asks[order.price][order.order_id] = order;
    }
}

void BookSide::modify(const Order& order) {
    cancel(order.order_id, order.side);
    add(order);
}

void BookSide::cancel(long order_id, const std::string& side) {
    if (side == "buy") {
        for (auto it = bids.begin(); it != bids.end(); ++it) {
            if (it->second.erase(order_id)) break;
        }
    } else {
        for (auto it = asks.begin(); it != asks.end(); ++it) {
            if (it->second.erase(order_id)) break;
        }
    }
}

void BookSide::execute(long order_id, const std::string& side, int quantity) {
    if (side == "buy") {
        for (auto& [price, orders] : bids) {
            auto it = orders.find(order_id);
            if (it != orders.end()) {
                it->second.quantity -= quantity;
                if (it->second.quantity <= 0) {
                    orders.erase(it);
                }
                break;
            }
        }
    } else {
        for (auto& [price, orders] : asks) {
            auto it = orders.find(order_id);
            if (it != orders.end()) {
                it->second.quantity -= quantity;
                if (it->second.quantity <= 0) {
                    orders.erase(it);
                }
                break;
            }
        }
    }
}

double BookSide::bestPrice(const std::string& side) const {
    if (side == "buy") {
        return bids.empty() ? 0.0 : bids.begin()->first;
    } else {
        return asks.empty() ? 0.0 : asks.begin()->first;
    }
}

int BookSide::totalVolumeAtBest(const std::string& side) const {
    int total = 0;
    if (side == "buy") {
        if (!bids.empty()) {
            for (const auto& [_, order] : bids.begin()->second) {
                total += order.quantity;
            }
        }
    } else {
        if (!asks.empty()) {
            for (const auto& [_, order] : asks.begin()->second) {
                total += order.quantity;
            }
        }
    }
    return total;
}