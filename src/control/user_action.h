#pragma once

#include <cstdint>

enum class UserActionType {
    INVALID,
    HELP,
    QUIT,
    STEP_FORWARD,
    STEP_BACK,
};

class UserAction {
private:
    UserActionType m_type;
    size_t m_count;

public:
    UserAction(UserActionType type, size_t count);

public:
    [[nodiscard]] auto type() const -> UserActionType;
    [[nodiscard]] auto count() const -> size_t;
};
