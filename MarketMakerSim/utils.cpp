#include "utils.hpp"
#include <chrono>

long get_timestamp() {
    return std::chrono::system_clock::now().time_since_epoch().count();
}

bool random_fill(double prob) {
    static std::mt19937 rng(std::random_device{}());
    std::bernoulli_distribution dist(prob);
    return dist(rng);
}

double random_walk() {
    static std::mt19937 rng(std::random_device{}());
    static std::normal_distribution<> dist(0.0, 0.5);
    return dist(rng);
}