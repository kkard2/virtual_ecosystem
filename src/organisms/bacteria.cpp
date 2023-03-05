#include "bacteria.h"

Bacteria::Bacteria(const SpeciesInfo &info) : Organism(info) {
}

auto Bacteria::clone() const -> std::unique_ptr<Organism> {
    return std::make_unique<Bacteria>(*this);
}

auto Bacteria::try_eat_type(ActionContext &context, CellType type) -> bool {
    auto food = context.random_neighbor(type);

    if (!food.has_value()) {
        return false;
    }

    auto position = food.value();
    context.map().organisms().erase(position);
    return true;
}

auto Bacteria::try_eat(ActionContext &context) const -> bool {
    if (try_eat_type(context, CellType::ALGA)) {
        return true;
    }

    if (try_eat_type(context, CellType::BACTERIA)) {
        return true;
    }

    return false;
}

auto Bacteria::try_move(ActionContext &context) const -> void {
    auto empty = context.random_neighbor(CellType::EMPTY);

    if (!empty.has_value()) {
        return;
    }

    auto &organisms = context.map().organisms();
    auto position = empty.value();
    organisms.emplace(position, std::move(organisms.at(context.position())));
    organisms.erase(context.position());
}

auto Bacteria::make_offspring() const -> std::unique_ptr<Organism> {
    return std::make_unique<Bacteria>(info());
}
