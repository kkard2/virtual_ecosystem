#pragma once

#include "organism.h"

class Alga : public Organism {
public:
    explicit Alga(const SpeciesInfo &info);

private:
    auto try_eat(ActionContext &context) const -> bool override;
    auto try_move(ActionContext &context) const -> void override;
    [[nodiscard]] auto make_offspring() const -> std::unique_ptr<Organism> override;
};
