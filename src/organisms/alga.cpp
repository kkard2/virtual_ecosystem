#include "alga.h"

Alga::Alga(Random &random, const SpeciesInfo &info) : Organism(random, info) {
}

auto Alga::clone() const -> std::unique_ptr<Organism> {
    return std::make_unique<Alga>(*this);
}

auto Alga::try_eat(ActionContext &context) const -> bool {
    // Photosynthesis
    return true;
}

auto Alga::try_move(ActionContext &context) const -> void {
    // Algae don't move
}

auto Alga::make_offspring(Random &random) const -> std::unique_ptr<Organism> {
    return std::make_unique<Alga>(random, info());
}
