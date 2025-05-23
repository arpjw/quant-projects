# LOBReplayEngine

A lightweight C++ Limit Order Book replay engine that parses historical market events (LOBSTER or ITCH-style logs) and reconstructs the top-of-book state in real time.

---

## Features

- Parses and replays events from CSV (add, modify, cancel, execute)
- Reconstructs live top-of-book prices and volumes
- Bid/ask depth tracking
- Clean modular design (LOB, parser, book sides, etc.)
- Extensible for logging, visual replay, or backtesting

---

## File Structure
```bash
LOBReplayEngine/
├── main.cpp # Runs the replay
├── LOB.hpp/cpp # Core book logic (apply, print top of book)
├── BookSide.hpp/cpp # Bid/ask queue management
├── Order.hpp # Order object definition
├── Event.hpp/cpp # Event struct and fields
├── Parser.hpp/cpp # CSV parser for loading event stream
├── utils.hpp/cpp # String utilities (lowercase)
├── events.csv # Sample event file (placed in project root)
├── CMakeLists.txt # Build file for CMake
```

---

## Build & Run

### Requirements

- C++17 or newer
- CMake 3.10+
- CLion or terminal with `g++`

### Build (terminal)

```bash
mkdir build && cd build
cmake ..
make
./LOBReplayEngine
```
### Sample CSV Format
```bash
timestamp,event_type,order_id,side,price,quantity
100001,add,1,buy,100.5,200
100002,add,2,sell,100.7,100
...
```

## Output Sample
```bash
Loaded 10 events.
Best Bid: 100.5 (150) | Best Ask: 100.6 (90)
...
```
