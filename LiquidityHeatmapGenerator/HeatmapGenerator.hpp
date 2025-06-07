#pragma once
#include "OrderBook.hpp"
#include <string>

class HeatmapGenerator {
public:
    HeatmapGenerator(const OrderBook& ob);
    void generate(const std::string& outputFilename) const;

private:
    const OrderBook& orderBook;
};
