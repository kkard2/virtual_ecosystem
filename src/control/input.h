#pragma once

#include <optional>
#include <string>
#include <filesystem>

#include "user_action.h"

class Input {
public:
    virtual auto read_seed() -> std::optional<uint64_t> = 0;
    virtual auto read_path() -> std::filesystem::path = 0;
    virtual auto read_action() -> std::optional<UserAction> = 0;
};
