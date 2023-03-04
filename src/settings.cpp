#include "settings.h"

Settings::Settings(
    char corpse_symbol, char empty_symbol, std::unique_ptr<SpeciesInfo> alga_info,
    std::unique_ptr<SpeciesInfo> fungus_info, std::unique_ptr<SpeciesInfo> bacteria_info
)
    : m_corpse_symbol(corpse_symbol)
    , m_empty_symbol(empty_symbol)
    , m_alga_info(std::move(alga_info))
    , m_fungus_info(std::move(fungus_info))
    , m_bacteria_info(std::move(bacteria_info))
    , m_species_info_by_type {
        {SpeciesType::ALGA,     *m_alga_info},
        {SpeciesType::FUNGUS,   *m_fungus_info},
        {SpeciesType::BACTERIA, *m_bacteria_info},
    }
    , m_species_info_by_symbol {
        {m_alga_info->symbol(),     *m_alga_info},
        {m_fungus_info->symbol(),   *m_fungus_info},
        {m_bacteria_info->symbol(), *m_bacteria_info}
    }
{
}
