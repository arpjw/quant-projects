#include "HeatmapGenerator.hpp"
#include <fstream>

HeatmapGenerator::HeatmapGenerator(const OrderBook& ob) : orderBook(ob) {}

void HeatmapGenerator::generate(const std::string& outputFilename) const {
    std::ofstream file(outputFilename);
    file << "side,price,volume\n";

    for (const auto& [price, volume] : orderBook.getBids()) {
        file << "bid," << price << "," << volume << "\n";
    }
    for (const auto& [price, volume] : orderBook.getAsks()) {
        file << "ask," << price << "," << volume << "\n";
    }
}
