# LiquidityHeatmapGenerator

A C++ tool to generate heatmap visualizations of order book liquidity over time.

---

## Overview

The **LiquidityHeatmapGenerator** reads a CSV file of historical order book snapshots and produces a heatmap image showing where liquidity clusters across time and price levels.

---

## Features

- Parse L2 (Level 2) order book CSV data
- Aggregate bid and ask liquidity over time
- Render and export visual heatmap (PNG)
- Easy to extend for additional metrics (order flow imbalance)

---

## Project Structure
```bash
LiquidityHeatmapGenerator/
├── CMakeLists.txt # CMake build configuration
├── main.cpp # CLI entry point
├── OrderBook.h/.cpp # Data loader and parser
├── HeatmapGenerator.h/.cpp # Visualization engine
```

---

## Build Instructions

1. Clone the repository
2. Create a build directory
3. Compile with CMake

```bash
git clone https://github.com/your-username/LiquidityHeatmapGenerator.git
cd LiquidityHeatmapGenerator
mkdir build && cd build
cmake ..
make
```
## Usage
```bash
./LiquidityHeatmapGenerator data/orderbook.csv output/heatmap.png
```
Each row in the input CSV should be formatted as:
```bash
timestamp, price, size, side
```
```bash
timestamp: Unix or ISO format
price: Price level
size: Order size at that level
side: bid or ask
```
## Formula Used
The liquidity heatmap uses a simple aggregation:
```bash
Liquidity(t, p) = BidSize(t, p) + AskSize(t, p)
```
Where:
```bash
`t`: time snapshot
`p`: price level
```
## Output
- X-axis: Time
- Y-axis: Price Levels
- Color: Depth (bid + ask size)
Sample output will be saved as a PNG in your specified output path.
