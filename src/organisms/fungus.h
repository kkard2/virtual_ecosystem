#pragma once

#include "organism.h"

class Fungus : public Organism {
public:
    explicit Fungus(const SpeciesInfo &info);

public:
    auto perform_action(ActionContext &context) -> void override;

private:
    auto eat(ActionContext &context) -> void;
    auto reproduce(ActionContext &context) -> void;
};
