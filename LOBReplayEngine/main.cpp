#include "Parser.hpp"
#include "LOB.hpp"
#include <iostream>

int main() {
    LOB lob;
    std::vector<Event> events = Parser::loadCSV("../events.csv");

    std::cout << "Loaded " << events.size() << " events.\n";

    for (const auto& event : events) {
        lob.apply(event);
        lob.printTopOfBook();
    }

    return 0;
}
