#include "fungus.h"

Fungus::Fungus(Random &random, const SpeciesInfo &info) : Organism(random, info) {
}

auto Fungus::clone() const -> std::unique_ptr<Organism> {
    return std::make_unique<Fungus>(*this);
}

auto Fungus::try_eat(ActionContext &context) const -> bool {
    auto food = context.random_neighbor(CellType::CORPSE);

    if (!food.has_value()) {
        return false;
    }

    auto position = food.value();
    context.map().organisms().erase(position);
    return true;
}

auto Fungus::try_move(ActionContext &context) const -> void {
    auto empty = context.random_neighbor(CellType::EMPTY);

    if (!empty.has_value()) {
        return;
    }

    auto &organisms = context.map().organisms();
    auto position = empty.value();
    organisms.emplace(position, std::move(organisms.at(context.position())));
    organisms.erase(context.position());
}

auto Fungus::make_offspring(Random &random) const -> std::unique_ptr<Organism> {
    return std::make_unique<Fungus>(random, info());
}
