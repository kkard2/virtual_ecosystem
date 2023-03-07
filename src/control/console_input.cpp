#include "console_input.h"
#include "user_action_parser.h"

#include <iostream>
#include <filesystem>

auto ConsoleInput::read_seed() -> std::optional<uint32_t> {
    std::cout << "Enter seed (empty for random):" << std::endl;
    auto line = std::string();
    std::getline(std::cin, line);

    if (line.empty()) {
        return std::nullopt;
    }

    while (true) {
        if (!line.empty()) {
            auto iss = std::istringstream(line);
            auto number = uint32_t();

            if (!!(iss >> number)) {
                return number;
            }

            std::cout << "Invalid input, try again:";
            std::getline(std::cin, line);
        }
    }
}

auto ConsoleInput::read_path() -> std::filesystem::path {
    std::cout << "Enter path to file:" << std::endl;
    auto line = std::string();
    std::getline(std::cin, line);
    auto path = std::filesystem::path(line);

    while (!std::filesystem::exists(path)) {
        std::cout << "File does not exist, try again:" << std::endl;
        std::getline(std::cin, line);
        path = std::filesystem::path(line);
    }

    return path;
}

auto ConsoleInput::read_action() -> std::optional<UserAction> {
    std::cout << "Enter action:" << std::endl;
    auto line = std::string();
    std::getline(std::cin, line);
    return UserActionParser::parse(line);
}
