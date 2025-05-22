cmake_minimum_required(VERSION 3.10)
project(OptionMarketSim)
set(CMAKE_CXX_STANDARD 17)
add_executable(OptionMarketSim
        main.cpp
        Asset.cpp
        Option.cpp
        Trader.cpp
        Utils.cpp
)
