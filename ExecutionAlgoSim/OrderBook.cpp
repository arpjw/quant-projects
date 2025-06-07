#include "OrderBook.hpp"
#include <iostream>

OrderBook::OrderBook() : orderIdCounter(0) {
    log.open("ExecutionLog.csv");
    log << "order_id,price,size\n";
}

void OrderBook::executeOrder(const Order& order) {
    log << order.id << "," << order.price << "," << order.size << "\n";
    std::cout << "Executed order: ID=" << order.id
              << " Price=" << order.price
              << " Size=" << order.size << "\n";
}
