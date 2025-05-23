#pragma once
#include "BookSide.hpp"
#include "Event.hpp"

class LOB {
private:
    BookSide book;

public:
    void apply(const Event& event);
    void printTopOfBook() const;
};