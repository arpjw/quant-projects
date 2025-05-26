# OFIAnalyzer

A real-time C++ tool for computing and visualizing **Order Flow Imbalance (OFI)** from live or historical order book data.

OFI is a powerful short-term signal that captures the **net pressure** between top-level bid and ask depth changes. This tool logs OFI alongside mid-price, allowing you to explore its predictive relationship to price movement.

---

## What It Computes

The Order Flow Imbalance at each timestamp is calculated as `OFI = ΔBidSize - ΔAskSize`

Where:
- `ΔBidSize` = change in size at the best bid (only if price unchanged)
- `ΔAskSize` = change in size at the best ask
- Mid-price = `(BestBid + BestAsk) / 2`

---

## File Structure
```bash
OFIAnalyzer/
├── main.cpp # Runs OFI calculation and logging
├── OrderBook.cpp/hpp # Tracks bid/ask and depth changes
├── Event.cpp/hpp # Defines LOB update event structure
├── Parser.cpp/hpp # Loads CSV-based order book updates
├── utils.cpp/hpp # String utilities (toLower)
├── ofi_events.csv # Sample input file (bid/ask updates)
├── ofi_output.csv # Output file with timestamp, OFI, mid
├── plot_ofi.py # Python plot of OFI vs mid-price
├── CMakeLists.txt # CMake build setup
```

---

## Build Instructions

### Requirements

- C++17
- CMake 3.10+
- Python 3 (optional for plotting)

### Build & Run (from root)

```bash
mkdir build && cd build
cmake ..
make
./OFIAnalyzer
```
Or just run from CLion or other IDEs with the above setup
## Sample Input
```bash
timestamp,event_type,price,size,side
100001,update,100.5,200,bid
100001,update,100.7,100,ask
100002,update,100.5,220,bid
100003,update,100.7,80,ask
100004,update,100.5,210,bid
100005,update,100.6,90,ask
```
## Output Format
Saved to `ofi_output.csv`
```bash
timestamp,OFI,MidPrice
100001,0,100.6
100002,20,100.6
100003,-20,100.6
...
```
## Plotting
Install Python packages (optional):
```bash
pip install pandas matplotlib
```
Run:
```bash
python3 plot_ofi.py
```
Generates 2-panel plot of:
 - Order Flow Imbbalance (OFI) over time
 - Mid-price over time
