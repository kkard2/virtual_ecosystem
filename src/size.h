#pragma once

#include <cstdint>

#include "position.h"

struct Size {
private:
    const uint32_t m_width;
    const uint32_t m_height;

public:
    Size(uint32_t width, uint32_t height);

public:
    [[nodiscard]] auto width() const -> uint32_t;
    [[nodiscard]] auto height() const -> uint32_t;

    [[nodiscard]] auto contains(const Position &position) const -> bool;
};
