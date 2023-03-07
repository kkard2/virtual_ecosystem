#pragma once

#include "user_action.h"

#include <optional>
#include <string>

class UserActionParser {
public:
    [[nodiscard]] static auto parse(const std::string &text) -> std::optional<UserAction>;
};
