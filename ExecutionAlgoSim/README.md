# ExecutionAlgoSim

A high-fidelity simulator for algorithmic execution strategies, starting with TWAP (Time-Weighted Average Price). Designed for testing how different strategies perform under order book constraints.

---

## Strategy Implemented

### TWAP (Time-Weighted Average Price)

TWAP slices a large parent order into equal-sized child orders spaced uniformly over time. This strategy is designed to minimize market impact and reduce signaling risk.

**TWAP Formula:**
TWAP = (Σ Priceᵢ × TimeIntervalᵢ) / TotalTime

In our discrete-time setting, this reduces to:


---

## Project Structure
```bash
ExecutionAlgoSim/
├── CMakeLists.txt # Build configuration
├── main.cpp # Runs the simulation
├── Order.hpp # Order data structure
├── OrderBook.hpp/.cpp # Order matching & state logic
├── TWAPStrategy.hpp/.cpp # Execution logic for TWAP
```

---

## Build & Run

### Prerequisites
- C++17 or higher
- CMake 3.15+
- Ninja or Make

### Build

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```
## Run
```bash
./ExecutionAlgoSim
```
