#include "alga.h"

Alga::Alga(const SpeciesInfo &info) : Organism(info) {
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

auto Alga::make_offspring() const -> std::unique_ptr<Organism> {
    return std::make_unique<Alga>(info());
}
