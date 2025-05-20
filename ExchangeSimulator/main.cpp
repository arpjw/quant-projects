#include "Exchange.hpp"
#include "Trader.hpp"

int main() {
    Exchange ex;
    ex.addTrader(Trader("T1"));
    ex.addTrader(Trader("T2"));
    ex.addTrader(Trader("MarketMaker"));

    ex.simulate(50); 

    return 0;
}
