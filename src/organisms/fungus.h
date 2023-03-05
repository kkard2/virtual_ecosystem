#pragma once

#include "organism.h"

class Fungus : public Organism {
public:
    explicit Fungus(const SpeciesInfo &info);

private:
    auto try_eat(ActionContext &context) -> bool override;
    auto try_reproduce(ActionContext &context) -> bool override;
    auto try_move(ActionContext &context) -> void override;
};
