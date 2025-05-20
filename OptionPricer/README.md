# OptionPricer

A simple C++ implementation of the Black-Scholes formula for pricing European call and put options.  

---

## What It Does

Given basic inputs like stock price, strike price, volatility, time to maturity, and interest rate, the program calculates the fair value of:
- A **European Call Option**
- A **European Put Option**

---

## Sample Output

European Call Option Price: 10.4506
European Put Option Price: 5.5735

---

## Financial Background

The **Black-Scholes-Merton model** is one of the most widely used tools in quantitative finance.  
It assumes:
- Constant volatility
- Risk-free rate over time
- Log-normal distribution of asset prices

## Formulas Used

**Call Option Price**  
`C = S * N(d1) - K * exp(-r * T) * N(d2)`

**Put Option Price**  
`P = K * exp(-r * T) * N(-d2) - S * N(-d1)`

**Where:**

- `d1 = [ln(S / K) + (r + (σ^2) / 2) * T] / (σ * sqrt(T))`
- `d2 = d1 - σ * sqrt(T)`

**Variables:**
- `S` = Stock price  
- `K` = Strike price  
- `T` = Time to maturity (in years)  
- `r` = Risk-free interest rate  
- `σ` = Volatility  
- `N()` = Standard normal cumulative distribution function

---

## How to Build & Run

### Requirements:
- CLion or any C++ compiler that supports C++17
- CMake 3.10+

### Steps:

1. Clone the parent repo and navigate to this subfolder:
```bash
git clone https://github.com/your-username/QuantProjects.git
cd QuantProjects/OptionPricer
```

2. Build & Run
```bash
mkdir build && cd build
cmake ..
make
./OptionPricer
```

## Files
```bash
OptionPricer/
├── main.cpp          # Contains all logic (Black-Scholes formula)
└── CMakeLists.txt    # CMake build file
```

## Customization
```bash
double S = 100.0;     // Stock price
double K = 100.0;     // Strike price
double T = 1.0;       // Time to expiration (in years)
double r = 0.05;      // Risk-free interest rate
double sigma = 0.2;   // Volatility
```
