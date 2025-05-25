cmake_minimum_required(VERSION 3.31)
project(HestonOptionSim)

set(CMAKE_CXX_STANDARD 20)

add_executable(HestonOptionSim
        main.cpp
        HestonModel.cpp
        Option.cpp
        CorrelatedRNG.cpp
        Utils.cpp
)
