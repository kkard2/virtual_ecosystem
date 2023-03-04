#pragma once

#include <string>

class Display {
public:
    [[nodiscard]] virtual auto to_string() const -> std::string = 0;
};
