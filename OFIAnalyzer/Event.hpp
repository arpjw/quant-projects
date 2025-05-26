#pragma once
#include <string>

struct Event {
    long timestamp;
    std::string type;  // always "update" for now
    double price;
    int size;
    std::string side;  // "bid" or "ask"
};