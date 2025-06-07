#include "TWAPStrategy.hpp"
#include <iostream>

int main() {
    OrderBook book;
    TWAPStrategy twap(book, 1000, 10); // totalQty, totalSteps
    twap.execute();
    std::cout << "Execution complete. Log saved to ExecutionLog.csv\n";
    return 0;
}
