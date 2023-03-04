#include "organism.h"

Organism::Organism(const SpeciesInfo &info, Position position)
    : m_info(info)
    , m_position(std::move(position))
    , m_age(info.health_min())
    , m_meals_eaten(0)
{
}

auto Organism::info() const -> const SpeciesInfo & {
    return m_info;
}

auto Organism::position() const -> const Position & {
    return m_position;
}

auto Organism::health() const -> uint32_t {
    return m_age;
}

auto Organism::meals_eaten() const -> uint32_t {
    return m_meals_eaten;
}

auto Organism::is_alive() const -> bool {
    return m_age >= info().health_max();
}

auto Organism::update() -> void {
    if (is_alive()) {
        m_age++;
    }
}

auto Organism::is_hungry() const -> bool {
    return m_meals_eaten >= info().meal_limit();
}
