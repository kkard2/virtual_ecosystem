#pragma once

#include "organism.h"

class Bacteria : public Organism {
public:
    explicit Bacteria(const SpeciesInfo &info);

private:
    static auto try_eat_type(ActionContext &context, CellType type) -> bool;

private:
    auto try_eat(ActionContext &context) -> bool override;
    auto try_reproduce(ActionContext &context) -> bool override;
    auto try_move(ActionContext &context) -> void override;
};
