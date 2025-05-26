#pragma once
#include "Event.hpp"

class OrderBook {
private:
    double bestBid, bestAsk;
    int bidSize, askSize;

public:
    OrderBook();

    void apply(const Event& e);

    double getBidPrice() const;
    double getAskPrice() const;
    int getBidSize() const;
    int getAskSize() const;
    double midPrice() const;
};