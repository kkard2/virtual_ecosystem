#pragma once

#include <optional>
#include <string>

class Input {
public:
    virtual auto read_seed() -> std::optional<uint64_t> = 0;
    virtual auto read_path() -> std::string = 0;
    virtual auto read_key() -> char = 0;
};
