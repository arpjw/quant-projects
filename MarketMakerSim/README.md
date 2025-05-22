# MarketMakerSim

A modular C++ simulator of market-making bots quoting bid/ask spreads around a dynamic mid-price.  
The simulation models inventory changes, trade fills, and PnL over time — ideal for understanding core principles of market microstructure and algorithmic market-making.

---

## Features

- Symmetric quoting around a simulated mid-price
- Poisson-style probabilistic fills
- Inventory and cash tracking per bot
- Mid-price random walk
- PnL reporting over time
- Easily extendable for more advanced behaviors

---

## Core Concepts

This simulator demonstrates:

- Market-making through passive liquidity provision
- Inventory risk and position management
- Bid-ask spread capture
- Mid-price movement simulation

---

## Project Structure
```bash
MarketMakerSim/
├── main.cpp # Simulation driver
├── MarketMaker.hpp/cpp # Market maker logic and quoting behavior
├── MarketSimulator.hpp/cpp # Mid-price simulation, fills, loop
├── Order.hpp # Order definition (price, side, etc.)
├── utils.hpp/cpp # RNG + timestamp utilities
└── CMakeLists.txt # Build system config
```

---

## Build & Run

### Prerequisites
- C++17
- CMake 3.10+
- CLion or g++ CLI

### Steps

```bash
git clone https://github.com/your-username/MarketMakerSim.git
cd MarketMakerSim
mkdir build && cd build
cmake ..
make
./MarketMakerSim
```

## Sample Output
```bash
Time step 0 | Mid Price: $100
MM_1 PnL: $-3.4
MM_2 PnL: $6.7
----------------------------
Time step 1 | Mid Price: $100.45
MM_1 PnL: $1.2
MM_2 PnL: $-2.1
```
