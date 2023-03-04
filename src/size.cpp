#include "size.h"

Size::Size(uint32_t width, uint32_t height) : m_width(width), m_height(height) {
}

auto Size::width() const -> uint32_t {
    return m_width;
}

auto Size::height() const -> uint32_t {
    return m_height;
}

auto Size::with_width(uint32_t new_width) const -> Size {
    return {new_width, m_height};
}

auto Size::with_height(uint32_t new_height) const -> Size {
    return {m_width, new_height};
}

std::string Size::to_string() const {
    return std::to_string(m_width) + "x" + std::to_string(m_height);
}
