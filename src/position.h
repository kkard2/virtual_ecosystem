#pragma once

#include <cstdint>

#include "display.h"

struct Position : public Display {
private:
    int32_t m_x;
    int32_t m_y;

public:
    Position(int32_t x, int32_t y);

public:
    [[nodiscard]] auto x() const -> int32_t;
    [[nodiscard]] auto y() const -> int32_t;

    [[nodiscard]] auto with_x(int32_t new_x) const -> Position;
    [[nodiscard]] auto with_y(int32_t new_y) const -> Position;

public:
    [[nodiscard]] std::string to_string() const override;
};

class PositionComparer {
public:
    [[nodiscard]] auto operator()(const Position &lhs, const Position &rhs) const -> bool;
};
