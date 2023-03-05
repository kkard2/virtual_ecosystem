#include "fungus.h"

Fungus::Fungus(const SpeciesInfo &info) : Organism(info) {
}

auto Fungus::try_eat(ActionContext &context) -> bool {
    auto food = context.random_neighbor(CellType::CORPSE);

    if (!food.has_value()) {
        return false;
    }

    auto position = food.value();
    context.map().organisms().erase(position);
    return true;
}

auto Fungus::try_reproduce(ActionContext &context) -> bool {
    auto empty = context.random_neighbor(CellType::EMPTY);

    if (!empty.has_value()) {
        return false;
    }

    auto position = empty.value();
    context.map().organisms().emplace(position, std::make_unique<Fungus>(info()));
    return true;
}

auto Fungus::try_move(ActionContext &context) -> void {
    auto empty = context.random_neighbor(CellType::EMPTY);

    if (!empty.has_value()) {
        return;
    }

    auto &organisms = context.map().organisms();
    auto position = empty.value();
    organisms.emplace(position, std::move(organisms.at(context.position())));
    organisms.erase(context.position());
}
