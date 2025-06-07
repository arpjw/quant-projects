#include <iostream>
#include "OrderBook.hpp"
#include "HeatmapGenerator.hpp"

int main() {
    OrderBook ob;
    ob.loadFromCSV("orderbook.csv");

    HeatmapGenerator heatmap(ob);
    heatmap.generate("heatmap_output.csv");

    std::cout << "Liquidity heatmap generated.\n";
    return 0;
}
