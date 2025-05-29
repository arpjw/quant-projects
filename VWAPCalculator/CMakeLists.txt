cmake_minimum_required(VERSION 3.10)
project(VWAPCalculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(VWAPCalculator main.cpp Trade.cpp VWAPCalculator.cpp Parser.cpp)
