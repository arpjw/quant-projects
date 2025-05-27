cmake_minimum_required(VERSION 3.31)
project(TickRuleClassifier)

set(CMAKE_CXX_STANDARD 20)

add_executable(TickRuleClassifier
        main.cpp
        Trade.cpp
        Parser.cpp
)
