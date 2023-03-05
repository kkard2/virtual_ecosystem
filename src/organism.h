#pragma once

#include "position.h"
#include "species_info.h"
#include "action_context.h"

class Organism {
private:
    const SpeciesInfo &m_info;

    uint32_t m_age;
    uint32_t m_meals_eaten;

public:
    // SAFETY: References must outlive this object.
    explicit Organism(const SpeciesInfo &info);

public:
    virtual auto perform_action(ActionContext &context) -> void = 0;

public:
    [[nodiscard]] auto info() const -> const SpeciesInfo &;
    [[nodiscard]] auto age() const -> uint32_t;
    [[nodiscard]] auto meals_eaten() const -> uint32_t;

    [[nodiscard]] auto is_alive() const -> bool;

    auto update() -> void;
private:
    [[nodiscard]] auto is_hungry() const -> bool;
};
