cmake_minimum_required(VERSION 3.31)
project(MarketMakerSim)

set(CMAKE_CXX_STANDARD 20)

add_executable(MarketMakerSim
        main.cpp
        MarketMaker.cpp
        MarketSimulator.cpp
        utils.cpp)
