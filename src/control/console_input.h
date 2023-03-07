#pragma once

#include "input.h"

class ConsoleInput : public Input {
public:
    auto read_seed() -> std::optional<uint64_t> override;
    auto read_path() -> std::string override;
    auto read_key() -> char override;
};
