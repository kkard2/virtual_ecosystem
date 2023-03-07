#include "position.h"

Position::Position(int32_t x, int32_t y) : m_x(x), m_y(y) {
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
