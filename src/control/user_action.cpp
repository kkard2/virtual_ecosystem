#include "user_action.h"

UserAction::UserAction(UserActionType type, size_t count)
    : m_type(type)
    , m_count(count)
{
}

auto UserAction::type() const -> UserActionType {
    return m_type;
}

auto UserAction::count() const -> size_t {
    return m_count;
}
