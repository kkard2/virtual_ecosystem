#include "input.h"

#include <iostream>
#include <sstream>

#ifdef _WIN32
#include <conio.h>
#else
#error "Unsupported platform"
#endif // _WIN32

auto Input::read_uint64() -> std::optional<uint64_t> {
    auto line = std::string();
    std::getline(std::cin, line);

    if (line.empty()) {
        return std::nullopt;
    }

    while (true) {
        if (!line.empty()) {
            auto iss = std::istringstream(line);
            uint64_t number;

            if (!!(iss >> number)) {
                return number;
            }

            std::cout << "Invalid input, try again:";
            std::getline(std::cin, line);
        }
    }
}

auto Input::read_action() -> UserAction {
    char key;

    // TODO: Start here

    do {
        key = static_cast<char>(_getch());
    } while (isdigit(key));
}
