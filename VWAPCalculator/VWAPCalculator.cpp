#include "VWAPCalculator.hpp"

double VWAPCalculator::calculateVWAP(const std::vector<Trade>& trades) {
    double totalVolume = 0;
    double totalValue = 0;
    for (const auto& trade : trades) {
        totalVolume += trade.size;
        totalValue += trade.price * trade.size;
    }
    return totalVolume == 0 ? 0.0 : totalValue / totalVolume;
}
