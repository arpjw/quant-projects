#include "TWAPStrategy.hpp"
#include <thread>
#include <chrono>

TWAPStrategy::TWAPStrategy(OrderBook& book, int totalQty, int steps)
    : orderBook(book), totalQuantity(totalQty), totalSteps(steps) {}

void TWAPStrategy::execute() {
    int sliceSize = totalQuantity / totalSteps;
    for (int i = 0; i < totalSteps; ++i) {
        Order order;
        order.id = i + 1;
        order.price = 100.0; // static mock price
        order.size = sliceSize;
        orderBook.executeOrder(order);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate delay
    }
}
