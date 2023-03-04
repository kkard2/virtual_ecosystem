#pragma once

#include <cstdint>

#include "display.h"

struct Size : public Display {
private:
    const uint32_t m_width;
    const uint32_t m_height;

public:
    Size(uint32_t width, uint32_t height);

public:
    [[nodiscard]] auto width() const -> uint32_t;
    [[nodiscard]] auto height() const -> uint32_t;

    [[nodiscard]] auto with_width(uint32_t new_width) const -> Size;
    [[nodiscard]] auto with_height(uint32_t new_height) const -> Size;

public:
    [[nodiscard]] std::string to_string() const override;
};
