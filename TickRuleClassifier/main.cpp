#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::vector<Trade> trades = Parser::loadCSV("../trades.csv");

    std::ofstream out("classified_trades.csv");
    out << "timestamp,price,size,label\n";

    double prevPrice = -1;

    for (const auto& t : trades) {
        std::string label = "unknown";

        if (prevPrice >= 0) {
            if (t.price > prevPrice) label = "buy";
            else if (t.price < prevPrice) label = "sell";
            else label = "same";  // optional
        }

        prevPrice = t.price;

        std::cout << "t=" << t.timestamp << " | price=" << t.price
                  << " | size=" << t.size << " | label=" << label << "\n";

        out << t.timestamp << "," << t.price << "," << t.size << "," << label << "\n";
    }

    out.close();
    return 0;
}