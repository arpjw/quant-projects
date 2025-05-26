cmake_minimum_required(VERSION 3.31)
project(OFIAnalyzer)

set(CMAKE_CXX_STANDARD 20)

add_executable(OFIAnalyzer
        main.cpp
        OrderBook.cpp
        Event.cpp
        Parser.cpp
        utils.cpp
)
