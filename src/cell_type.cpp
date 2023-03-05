#include "cell_type.h"

auto cell_type_from_species_type(SpeciesType type) -> CellType {
    switch (type) {
        case SpeciesType::ALGA:
            return CellType::ALGA;
        case SpeciesType::FUNGUS:
            return CellType::FUNGUS;
        case SpeciesType::BACTERIA:
            return CellType::BACTERIA;
        default:
            return CellType::EMPTY;
    }
}
