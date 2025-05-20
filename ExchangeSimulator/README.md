# exchange simulator

a modular c++ simulation of a limit-order book–based financial exchange.  
this project supports multiple autonomous trading agents, order matching using price-time priority, and trade execution logging — built from scratch for educational and quantitative research purposes.

---

## what it does

- simulates a live exchange with basic trader agents
- matches BUY and SELL limit orders using price-time priority
- logs all executed trades
- built with a fully object-oriented structure:
  - `Trader`, `Order`, `OrderBook`, `Exchange`

---

## project structure
```bash
ExchangeSimulator/
├── main.cpp # entry point — runs simulation
├── Order.hpp # order struct with price, qty, and metadata
├── Trade.hpp # trade struct with execution details
├── OrderBook.hpp/cpp # matching engine implementation
├── Trader.hpp/AI.cpp # trader class with random order generator
├── Exchange.hpp/cpp # coordinates traders and engine
└── CMakeLists.txt # build system config
```

---

## how to build & run

### prerequisites
- c++17 compiler
- cmake 3.10+
- clion or terminal

### run commands

```bash
cd ExchangeSimulator
mkdir build && cd build
cmake ..
make
./ExchangeSimulator
```
### executed trades 
```bash
BUY#1 <--> SELL#2 | Qty: 40 @ $96
BUY#4 <--> SELL#3 | Qty: 20 @ $98
```
