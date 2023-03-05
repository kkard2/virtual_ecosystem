#pragma once

#include "species_type.h"

enum class CellType {
    EMPTY,
    WALL,
    ALGA,
    FUNGUS,
    BACTERIA,
    CORPSE,
};

auto cell_type_from_species_type(SpeciesType type) -> CellType;
