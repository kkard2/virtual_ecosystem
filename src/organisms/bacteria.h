#pragma once

#include "organism.h"

class Bacteria : public Organism {
public:
    Bacteria(Random &random, const SpeciesInfo &info);

public:
    [[nodiscard]] auto clone() const -> std::unique_ptr<Organism> override;

private:
    static auto try_eat_type(ActionContext &context, CellType type) -> bool;

private:
    auto try_eat(ActionContext &context) const -> bool override;
    auto try_move(ActionContext &context) const -> void override;
    [[nodiscard]] auto make_offspring(Random &random) const -> std::unique_ptr<Organism> override;
};
