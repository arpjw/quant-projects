cmake_minimum_required(VERSION 3.31)
project(LOBReplayEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(LOBReplayEngine
        main.cpp
        LOB.cpp
        BookSide.cpp
        Event.cpp
        Parser.cpp
        utils.cpp
)
