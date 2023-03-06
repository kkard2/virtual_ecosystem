#pragma once

#include <optional>

#include "user_action.h"

class Input {
public:
    static auto read_uint64() -> std::optional<uint64_t>;
    static auto read_action() -> UserAction;
};
