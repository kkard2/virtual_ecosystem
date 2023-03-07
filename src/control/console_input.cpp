#include "console_input.h"

#include <iostream>
#include <sstream>

#ifdef _WIN32
#include <conio.h>
#else
#error "Unsupported platform"
#endif // _WIN32

auto ConsoleInput::read_seed() -> std::optional<uint64_t> {
    auto line = std::string();
    std::getline(std::cin, line);

    if (line.empty()) {
        return std::nullopt;
    }

    while (true) {
        if (!line.empty()) {
            auto iss = std::istringstream(line);
            auto number = uint64_t();

            if (!!(iss >> number)) {
                return number;
            }

            std::cout << "Invalid input, try again:";
            std::getline(std::cin, line);
        }
    }
}

auto ConsoleInput::read_path() -> std::string {
    auto line = std::string();
    std::getline(std::cin, line);

    return line;
}

auto ConsoleInput::read_key() -> char {
#ifdef _WIN32
    return static_cast<char>(_getch());
#else
#error "Unsupported platform"
#endif // _WIN32
}
