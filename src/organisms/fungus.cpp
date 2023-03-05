#include "fungus.h"

Fungus::Fungus(const SpeciesInfo &info) : Organism(info) {
}

auto Fungus::perform_action(ActionContext &context) -> void {
    if (!is_alive()) {
        return;
    }

    if (is_hungry()) {
        eat(context);
        return;
    }

    reproduce(context);
}

auto Fungus::eat(ActionContext &context) -> void {
    auto food = context.random_neighbor(CellType::CORPSE);

    if (!food.has_value()) {
        return;
    }

    auto position = food.value();
    context.map().organisms().erase(position);
    m_meals_eaten++;
}

auto Fungus::reproduce(ActionContext &context) -> void {
    if (is_hungry()) {
        throw std::runtime_error("Fungus is hungry and is trying to reproduce.");
    }

    auto empty = context.random_neighbor(CellType::EMPTY);

    if (!empty.has_value()) {
        return;
    }

    auto position = empty.value();
    context.map().organisms().emplace(position, std::make_unique<Fungus>(info()));
    m_meals_eaten -= info().offspring_cost();
}
