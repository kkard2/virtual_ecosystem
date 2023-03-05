#pragma once

#include <memory>

#include "../position.h"
#include "../settings/species_info.h"
#include "../action_context.h"

// Fixes cyclic reference
class ActionContext;

class Organism {
private:
    const SpeciesInfo &m_info;
    uint32_t m_age;
    uint32_t m_meals_eaten;

public:
    explicit Organism(const SpeciesInfo &info);
    virtual ~Organism() = default;

public:
    [[nodiscard]] virtual auto clone() const -> std::unique_ptr<Organism> = 0;

protected:
    virtual auto try_eat(ActionContext &context) const -> bool = 0;
    virtual auto try_move(ActionContext &context) const -> void = 0;
    [[nodiscard]] virtual auto make_offspring() const -> std::unique_ptr<Organism> = 0;

public:
    [[nodiscard]] auto info() const -> const SpeciesInfo &;
    [[nodiscard]] auto age() const -> uint32_t;
    [[nodiscard]] auto meals_eaten() const -> uint32_t;

    [[nodiscard]] auto is_alive() const -> bool;

    auto update() -> void;
    auto perform_action(ActionContext &context) -> void;

    // Should only be used to create corpses when loading a map.
    auto kill() -> void;

private:
    [[nodiscard]] auto is_hungry() const -> bool;
    auto try_reproduce(ActionContext &context) const -> bool;
};
