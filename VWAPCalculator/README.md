# VWAPCalculator

This is a minimal C++ program that calculates the **Volume-Weighted Average Price (VWAP)** from a CSV of trade data.

VWAP is calculated as:

```bash
VWAP = (∑ (Price × Volume)) / (∑ Volume)
```

---

## Files

- `main.cpp`: Loads the trades and prints VWAP
- `Trade.hpp/cpp`: Represents a trade object
- `Parser.hpp/cpp`: Loads and parses CSV data
- `VWAPCalculator.hpp/cpp`: Computes the VWAP
- `trades.csv`: Sample trade data
- `CMakeLists.txt`: CMake build setup

---

## How to Run

1. Build the project with CLion or via terminal:
   ```bash
   cmake -B build
   cmake --build build
   ./build/VWAPCalculator
   
2. Make sure `trades.csv` is in the same directory as your binary:
  ```bash
  /path/to/your/project/cmake-build-debug/trades.csv
  ```

---

## Sample 
File: `trades.csv`
```bash
timestamp,price,volume
2024-01-01T10:00:00Z,100.5,200
2024-01-01T10:01:00Z,101.0,300
2024-01-01T10:02:00Z,99.5,500
```

---

## Output
```bash
VWAP: 100.05
```

---

## Notes
- If VWAP is `0,` make sure
  - The file is named `trades.csv`
  - It's in the correct directory
  - No rows have zero volume
