# ExchangeSimulator

A modular C++ simulation of a limit-order book–based financial exchange.  
This project supports multiple autonomous trading agents, order matching using price-time priority, and trade execution logging — built from scratch for educational and quantitative research purposes.

---

## What It Does

- Simulates a live exchange with basic trader agents
- Matches BUY and SELL limit orders using price-time priority
- Logs all executed trades
- Built with a fully object-oriented structure:
  - `Trader`, `Order`, `OrderBook`, `Exchange`

---

## Project Structure
```bash
ExchangeSimulator/
├── main.cpp # Entry point — runs simulation
├── Order.hpp # Order struct with price, qty, and metadata
├── Trade.hpp # Trade struct with execution details
├── OrderBook.hpp/cpp # Matching engine implementation
├── Trader.hpp/AI.cpp # Trader class with random order generator
├── Exchange.hpp/cpp # Coordinates traders and engine
└── CMakeLists.txt # Build system config
```

---

## How to Build & Run

### Prerequisites
- C++17 compiler
- CMake 3.10+
- CLion or terminal

### Run Commands

```bash
cd ExchangeSimulator
mkdir build && cd build
cmake ..
make
./ExchangeSimulator
```
### Executed Trades 
```bash
BUY#1 <--> SELL#2 | Qty: 40 @ $96
BUY#4 <--> SELL#3 | Qty: 20 @ $98
```
