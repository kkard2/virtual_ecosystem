#include "organism.h"

Organism::Organism(Random &random, const SpeciesInfo &info)
    : m_info(info)
    , m_age_max(random.next(info.age_min(), info.age_max()))
    , m_age(0)
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
    return m_age < m_age_max;
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

auto Organism::kill() -> void {
    m_age = m_age_max;
}

auto Organism::is_hungry() const -> bool {
    return m_meals_eaten < info().meal_limit();
}

auto Organism::try_reproduce(ActionContext &context) const -> bool {
    auto empty = context.random_neighbor(CellType::EMPTY);

    if (!empty.has_value()) {
        return false;
    }

    auto position = empty.value();
    context.map().organisms().emplace(position, make_offspring(context.random()));
    return true;
}
