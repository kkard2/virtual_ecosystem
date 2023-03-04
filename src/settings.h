#pragma once

#include <map>
#include <memory>

#include "size.h"
#include "species_info.h"

class Settings {
private:
    const char m_corpse_symbol;
    const char m_empty_symbol;
    const std::unique_ptr<SpeciesInfo> m_alga_info;
    const std::unique_ptr<SpeciesInfo> m_fungus_info;
    const std::unique_ptr<SpeciesInfo> m_bacteria_info;

    const std::map<SpeciesType, const SpeciesInfo &> m_species_info_by_type;
    const std::map<char, const SpeciesInfo &> m_species_info_by_symbol;

public:
    Settings(
        char corpse_symbol, char empty_symbol, std::unique_ptr<SpeciesInfo> alga_info,
        std::unique_ptr<SpeciesInfo> fungus_info, std::unique_ptr<SpeciesInfo> bacteria_info
    );

    Settings(const Settings &) = delete;
    auto operator=(const Settings &) -> Settings & = delete;

    ~Settings() = default;

public:
    [[nodiscard]] static auto default_settings() -> const Settings &;

public:
    [[nodiscard]] auto corpse_symbol() const -> char;
    [[nodiscard]] auto empty_symbol() const -> char;
    [[nodiscard]] auto alga_info() const -> const SpeciesInfo &;
    [[nodiscard]] auto fungus_info() const -> const SpeciesInfo &;
    [[nodiscard]] auto bacteria_info() const -> const SpeciesInfo &;

    [[nodiscard]] auto species_info(SpeciesType type) const -> const SpeciesInfo &;
    [[nodiscard]] auto species_info(char symbol) const -> const SpeciesInfo &;
};
