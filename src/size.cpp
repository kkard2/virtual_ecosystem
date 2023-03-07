#include "size.h"

Size::Size(uint32_t width, uint32_t height) : m_width(width), m_height(height) {
}

auto Size::width() const -> uint32_t {
    return m_width;
}

auto Size::height() const -> uint32_t {
    return m_height;
}

auto Size::contains(const Position &position) const -> bool {
    return
        position.x() >= 0 && static_cast<uint32_t>(position.x()) < m_width &&
        position.y() >= 0 && static_cast<uint32_t>(position.y()) < m_height;
}
