#include "position.h"

Position::Position(int32_t x, int32_t y) : m_x(x), m_y(y) {
}

auto Position::with_x(int32_t new_x) const -> Position {
    return {new_x, m_y};
}

auto Position::with_y(int32_t new_y) const -> Position {
    return {m_x, new_y};
}

std::string Position::to_string() const {
    return "[" + std::to_string(m_x) + ", " + std::to_string(m_y) + "]";
}

auto Position::x() const -> int32_t {
    return m_x;
}

auto Position::y() const -> int32_t {
    return m_y;
}

auto PositionComparer::operator()(const Position &lhs, const Position &rhs) const -> bool {
    return lhs.x() < rhs.x() || (lhs.x() == rhs.x() && lhs.y() < rhs.y());
}
