#include "MarketSimulator.hpp"
#include "utils.hpp"
#include <iostream>

MarketSimulator::MarketSimulator(std::vector<std::shared_ptr<MarketMaker>> b)
    : bots(std::move(b)), midPrice(100.0) {}

void MarketSimulator::run(int steps) {
    for (int t = 0; t < steps; ++t) {
        std::cout << "Time step " << t << " | Mid Price: $" << midPrice << "\n";

        for (auto& bot : bots) {
            auto [bid, ask] = bot->generateQuotes(midPrice, get_timestamp());

            if (random_fill()) bot->handleFill(bid);
            if (random_fill()) bot->handleFill(ask);

            std::cout << bot->getId() << " PnL: $" << bot->getPnL(midPrice) << "\n";
        }

        midPrice += random_walk();
        std::cout << "----------------------------\n";
    }
}