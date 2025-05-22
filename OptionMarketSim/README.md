# OptionMarketSim

A discrete-time C++ simulator for option pricing, delta hedging, and risk management.  
The simulation models a European call option priced with Black-Scholes, including real-time tracking of Greeks, implied volatility skews, and trader PnL.

---

## What It Does

- Simulates a stochastic asset path using geometric Brownian motion
- Prices European call options with Black-Scholes
- Supports implied volatility skew (ITM, ATM, OTM)
- Tracks Greeks: Delta (Δ), Gamma (Γ), Theta (Θ)
- Simulates dynamic delta hedging by a trader
- Logs all values to CSV
- Visualizes output with Matplotlib

---

## Project Structure

```bash
OptionMarketSim/
├── main.cpp # Simulation driver and logger
├── Asset.hpp / .cpp # Underlying price evolution
├── Option.hpp / .cpp # Option pricing and Greeks
├── Trader.hpp / .cpp # Delta hedging and PnL logic
├── Utils.hpp / .cpp # Normal CDF/PDF, RNG
├── plot_simulation.py # PnL/Greek/Price visualization (Python)
└── CMakeLists.txt # Build config
```

---

## How to Build & Run

### Requirements

- C++17 compiler (g++, clang++, or CLion)
- Python 3 + `matplotlib`, `pandas` (for visualization)

### Build + Run

```bash
mkdir build && cd build
cmake ..
make
./OptionMarketSim
```

### Visualize
Run this after the program is done running
```bash
python3 plot_simulation.py
```

## Output Example
```bash
CSV: simulation_log.csv
```
Columns: Step, Asset Price, Option Value, Δ, Γ, Θ, PnL
Matplotlib will generate:
 - PnL over time
 - Delta and Gamma curves
 - Asset and option price trends
