#pragma once
#include <string>

struct Event {
    long timestamp;
    std::string type;  // add, modify, cancel, execute
    long order_id;
    std::string side;
    double price;
    int quantity;
};