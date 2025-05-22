#include "MarketSimulator.hpp"
#include "MarketMaker.hpp"
#include <vector>
#include <memory>

int main() {
    std::vector<std::shared_ptr<MarketMaker>> bots = {
        std::make_shared<MarketMaker>("MM_1"),
        std::make_shared<MarketMaker>("MM_2")
    };

    MarketSimulator sim(bots);
    sim.run(100);

    return 0;
}