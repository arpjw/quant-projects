#include "Parser.hpp"
#include "OrderBook.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

int main() {
    std::vector<Event> events = Parser::loadCSV("../ofi_events.csv");

    OrderBook book;
    std::ofstream log("ofi_output.csv");
    log << "timestamp,OFI,MidPrice\n";

    std::cout << std::fixed << std::setprecision(4);

    for (const auto& e : events) {
        double oldBid = book.getBidPrice();
        double oldAsk = book.getAskPrice();
        int oldBidSize = book.getBidSize();
        int oldAskSize = book.getAskSize();

        book.apply(e);

        double newBid = book.getBidPrice();
        double newAsk = book.getAskPrice();
        int newBidSize = book.getBidSize();
        int newAskSize = book.getAskSize();

        int dBid = (newBid == oldBid) ? newBidSize - oldBidSize : newBidSize;
        int dAsk = (newAsk == oldAsk) ? newAskSize - oldAskSize : newAskSize;

        int ofi = dBid - dAsk;
        double mid = book.midPrice();

        std::cout << "t=" << e.timestamp << " | OFI=" << ofi << " | Mid=" << mid << "\n";
        log << e.timestamp << "," << ofi << "," << mid << "\n";
    }

    log.close();
    return 0;
}