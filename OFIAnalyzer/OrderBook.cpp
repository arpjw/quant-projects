#include "OrderBook.hpp"

OrderBook::OrderBook() : bestBid(0), bestAsk(0), bidSize(0), askSize(0) {}

void OrderBook::apply(const Event& e) {
    if (e.side == "bid") {
        bestBid = e.price;
        bidSize = e.size;
    } else if (e.side == "ask") {
        bestAsk = e.price;
        askSize = e.size;
    }
}

double OrderBook::getBidPrice() const { return bestBid; }
double OrderBook::getAskPrice() const { return bestAsk; }
int OrderBook::getBidSize() const { return bidSize; }
int OrderBook::getAskSize() const { return askSize; }

double OrderBook::midPrice() const {
    if (bestBid > 0 && bestAsk > 0)
        return 0.5 * (bestBid + bestAsk);
    return 0.0;
}