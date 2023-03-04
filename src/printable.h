#pragma once

#include <string>

class Printable {
public:
    [[nodiscard]] virtual auto to_string() const -> std::string = 0;
};
