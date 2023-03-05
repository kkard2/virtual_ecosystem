#include <stdexcept>
#include <unordered_set>

#include "settings.h"

Settings::Settings(
    char corpse_symbol, char empty_symbol,
    const SpeciesInfo &alga_info, const SpeciesInfo &fungus_info, const SpeciesInfo &bacteria_info
)
    : m_corpse_symbol(corpse_symbol)
    , m_empty_symbol(empty_symbol)
    , m_alga_info(std::move(alga_info))
    , m_fungus_info(std::move(fungus_info))
    , m_bacteria_info(std::move(bacteria_info))
{
    assert_info_types_correct();
    assert_symbols_unique();
}

auto Settings::default_settings() -> const Settings & {
    static const auto settings = Settings(
        '+', '_',
        SpeciesInfo::default_alga(),
        SpeciesInfo::default_fungus(),
        SpeciesInfo::default_bacteria()
    );

    return settings;
}

void Settings::assert_info_types_correct() const {
    if (m_alga_info.type() != SpeciesType::ALGA) {
        throw std::runtime_error("Alga info has wrong type");
    }

    if (m_fungus_info.type() != SpeciesType::FUNGUS) {
        throw std::runtime_error("Fungus info has wrong type");
    }

    if (m_bacteria_info.type() != SpeciesType::BACTERIA) {
        throw std::runtime_error("Bacteria info has wrong type");
    }
}

void Settings::assert_symbols_unique() const {
    auto symbols = std::unordered_set<char>();

    symbols.insert(m_alga_info.symbol());

    if (!symbols.insert(m_fungus_info.symbol()).second) {
        throw std::runtime_error("Fungus symbol is not unique");
    }

    if (!symbols.insert(m_bacteria_info.symbol()).second) {
        throw std::runtime_error("Bacteria symbol is not unique");
    }

    if (!symbols.insert(m_corpse_symbol).second) {
        throw std::runtime_error("Corpse symbol is not unique");
    }

    if (!symbols.insert(m_empty_symbol).second) {
        throw std::runtime_error("Empty symbol is not unique");
    }
}

auto Settings::corpse_symbol() const -> char {
    return m_corpse_symbol;
}

auto Settings::empty_symbol() const -> char {
    return m_empty_symbol;
}

auto Settings::alga_info() const -> const SpeciesInfo & {
    return m_alga_info;
}

auto Settings::fungus_info() const -> const SpeciesInfo & {
    return m_fungus_info;
}

auto Settings::bacteria_info() const -> const SpeciesInfo & {
    return m_bacteria_info;
}
