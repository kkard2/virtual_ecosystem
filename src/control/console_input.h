#pragma once

#include "input.h"

class ConsoleInput : public Input {
public:
    auto read_seed() -> std::optional<uint32_t> override;
    auto read_path() -> std::filesystem::path override;
    auto read_action() -> std::optional<UserAction> override;
};
