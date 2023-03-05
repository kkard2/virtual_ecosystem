#include "organism.h"

Organism::Organism(const SpeciesInfo &info)
    : m_info(info)
    , m_age(info.age_min())
    , m_meals_eaten(0)
{
}

auto Organism::info() const -> const SpeciesInfo & {
    return m_info;
}

auto Organism::age() const -> uint32_t {
    return m_age;
}

auto Organism::meals_eaten() const -> uint32_t {
    return m_meals_eaten;
}

auto Organism::is_alive() const -> bool {
    return m_age >= info().age_max();
}

auto Organism::update() -> void {
    if (is_alive()) {
        m_age++;
    }
}

auto Organism::perform_action(ActionContext &context) -> void {
    if (!is_alive()) {
        return;
    }

    auto performed_action = false;

    if (is_hungry()) {
        if (try_eat(context)) {
            m_meals_eaten++;
            performed_action = true;
        }
    } else {
        if (try_reproduce(context)) {
            m_meals_eaten -= info().offspring_cost();
            performed_action = true;
        }
    }

    if (!performed_action) {
        try_move(context);
    }
}

auto Organism::is_hungry() const -> bool {
    return m_meals_eaten >= info().meal_limit();
}