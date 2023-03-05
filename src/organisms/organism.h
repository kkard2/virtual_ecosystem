#pragma once

#include "../position.h"
#include "../species_info.h"
#include "../action_context.h"

class Organism {
protected:
    uint32_t m_meals_eaten;

private:
    const SpeciesInfo &m_info;
    uint32_t m_age;

public:
    // SAFETY: References must outlive this object (and its offspring).
    explicit Organism(const SpeciesInfo &info);

public:
    virtual auto perform_action(ActionContext &context) -> void = 0;

public:
    [[nodiscard]] auto info() const -> const SpeciesInfo &;
    [[nodiscard]] auto age() const -> uint32_t;
    [[nodiscard]] auto meals_eaten() const -> uint32_t;

    [[nodiscard]] auto is_alive() const -> bool;

    auto update() -> void;

protected:
    [[nodiscard]] auto is_hungry() const -> bool;
};
