# HestonOptionSim

A discrete-time C++ simulator of a European call option under the **Heston stochastic volatility model**. Tracks asset price, volatility, and Black-Scholes-derived option pricing and Greeks over time.

---

## What It Does

- Simulates an asset following the Heston model:
```bash
dSₜ = μ Sₜ dt + √(vₜ) Sₜ dW₁

dvₜ = κ(θ - vₜ) dt + σᵥ √(vₜ) dW₂
```

- Where:
- `Sₜ` is the asset price
- `vₜ` is the instantaneous variance
- `W₁`, `W₂` are correlated Brownian motions (ρ)
- At each step:
- Updates asset price and variance
- Computes Black-Scholes price and Greeks (Δ, Γ, Θ)
- Logs all output to CSV

---

## File Structure
```bash
HestonOptionSim/
├── main.cpp # Simulation driver
├── HestonModel.cpp/hpp # Asset + volatility simulation
├── Option.cpp/hpp # BS pricing & Greeks (with dynamic vol)
├── CorrelatedRNG.cpp/hpp #Correlated Brownian motion
├── Utils.cpp/hpp # Normal CDF/PDF and RNG
├── CMakeLists.txt # Build configuration
├── heston_output.csv # Output file (generated)
└── plot_sim.py # Visualization (optional)
```

---

## How to Build & Run

### Requirements

- C++17 or higher
- CMake 3.10+
- Python 3 (for plotting, optional)

### Compile & Run

```bash
mkdir build && cd build
cmake ..
make
./HestonOptionSim
```
## Output
CSV will be saved as `heston_output.csv` with columns:
```bash
Step, Time, Asset, Volatility, OptionPrice, Delta, Gamma, Theta
```
## Optional: Visualize with Python
Install Dependencies 
```bash
pip install matplotlib pandas
```
Then run:
```bash
python3 plot_sim.py
```
You'll see plots of 
```bash
 - Asset price 𝑆𝑡
 - Instantaneous variance 𝑣𝑡
 - Option price over time
 - Greeks (Delta, Gamma, Theta)
```

## Parameters Used
```bash
S0       = 100.0      # Initial price
v0       = 0.04       # Initial variance
mu       = 0.05       # Drift of asset
kappa    = 2.0        # Speed of mean reversion
theta    = 0.04       # Long-run variance
sigma_v  = 0.3        # Vol of vol
rho      = -0.7       # Correlation (W1, W2)
T        = 1.0 year
steps    = 252
```
