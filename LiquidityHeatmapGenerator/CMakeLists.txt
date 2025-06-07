cmake_minimum_required(VERSION 3.17)
project(LiquidityHeatmapGenerator)

set(CMAKE_CXX_STANDARD 20)

# Add all source files
add_executable(LiquidityHeatmapGenerator
        main.cpp
        OrderBook.cpp
        HeatmapGenerator.cpp
)

# Include header files
target_include_directories(LiquidityHeatmapGenerator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
