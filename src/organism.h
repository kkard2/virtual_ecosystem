#pragma once

#include "position.h"
#include "species_info.h"

class Organism {
private:
    const SpeciesInfo &m_info;

    Position m_position;
    uint32_t m_age;
    uint32_t m_meals_eaten;

public:
    // SAFETY: References must outlive this object.
    Organism(const SpeciesInfo &info, Position position);

public:
    [[nodiscard]] auto info() const -> const SpeciesInfo &;
    [[nodiscard]] auto position() const -> const Position &;
    [[nodiscard]] auto age() const -> uint32_t;
    [[nodiscard]] auto meals_eaten() const -> uint32_t;

    [[nodiscard]] auto is_alive() const -> bool;

    auto update() -> void;
private:
    [[nodiscard]] auto is_hungry() const -> bool;

};
