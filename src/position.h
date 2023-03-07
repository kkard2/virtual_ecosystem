#pragma once

#include <cstdint>

struct Position {
private:
    int32_t m_x;
    int32_t m_y;

public:
    Position(int32_t x, int32_t y);

public:
    [[nodiscard]] auto x() const -> int32_t;
    [[nodiscard]] auto y() const -> int32_t;
};

class PositionComparer {
public:
    [[nodiscard]] auto operator()(const Position &lhs, const Position &rhs) const -> bool;
};
