# TickRuleClassifier

A simple C++ program to classify trades as **buy- or sell-initiated** using the **tick rule**, based on trade price movements.

This is one of the most fundamental labeling techniques in market microstructure, useful for building signed volume, imbalance indicators, and supervised alpha models.

---

## What It Does

For a series of trades ordered by time:

- If `price > previous_price`, label as `"buy"`
- If `price < previous_price`, label as `"sell"`
- If `price == previous_price`, label as `"same"` (optional)

---

## File Structure
```bash
TickRuleClassifier/
├── main.cpp # Reads, classifies, logs trades
├── Trade.cpp / .hpp # Trade struct with timestamp/price/size
├── Parser.cpp / .hpp # Loads trades from CSV
├── trades.csv # Sample trade log (timestamped)
├── classified_trades.csv # Output with labels
├── CMakeLists.txt # Build config
```

---

## Example

### Input: `trades.csv`

```csv
timestamp,price,size
100001,100.5,200
100002,100.6,150
100003,100.55,100
100004,100.55,120
100005,100.7,180
```
## Output: 
File: `classified_trades.csv`
```bash
timestamp,price,size,label
100001,100.5,200,unknown
100002,100.6,150,buy
100003,100.55,100,sell
100004,100.55,120,same
100005,100.7,180,buy
```

## Build & Run
Requirements
 - C++17 or later
 - CMake 3.10+
### Steps
```bash
mkdir build && cd build
cmake ..
make
./TickRuleClassifier
```

