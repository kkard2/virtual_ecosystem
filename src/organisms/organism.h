#pragma once

#include "../position.h"
#include "../species_info.h"
#include "../action_context.h"

class Organism {
private:
    const SpeciesInfo &m_info;
    uint32_t m_age;
    uint32_t m_meals_eaten;

public:
    // SAFETY: References must outlive this object (and its offspring).
    explicit Organism(const SpeciesInfo &info);

protected:
    virtual auto try_eat(ActionContext &context) -> bool = 0;
    virtual auto try_reproduce(ActionContext &context) -> bool = 0;
    virtual auto try_move(ActionContext &context) -> void = 0;

public:
    [[nodiscard]] auto info() const -> const SpeciesInfo &;
    [[nodiscard]] auto age() const -> uint32_t;
    [[nodiscard]] auto meals_eaten() const -> uint32_t;

    [[nodiscard]] auto is_alive() const -> bool;

    auto update() -> void;
    auto perform_action(ActionContext &context) -> void;

protected:
    [[nodiscard]] auto is_hungry() const -> bool;
};
