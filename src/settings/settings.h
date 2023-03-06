#pragma once

#include <map>
#include <memory>
#include <optional>

#include "species_info.h"
#include "../organisms/organism.h"

class Settings {
private:
    const char m_corpse_symbol;
    const char m_empty_symbol;
    const std::string m_corpse_name;
    const SpeciesInfo &m_alga_info;
    const SpeciesInfo &m_fungus_info;
    const SpeciesInfo &m_bacteria_info;

public:
    Settings(
        char corpse_symbol, char empty_symbol, std::string corpse_name,
        const SpeciesInfo &alga_info, const SpeciesInfo &fungus_info, const SpeciesInfo &bacteria_info
    );

    Settings(const Settings &) = delete;
    auto operator=(const Settings &) -> Settings & = delete;

    ~Settings() = default;

public:
    [[nodiscard]] static auto default_settings() -> const Settings &;

public:
    [[nodiscard]] auto corpse_symbol() const -> char;
    [[nodiscard]] auto empty_symbol() const -> char;
    [[nodiscard]] auto corpse_name() const -> const std::string &;
    [[nodiscard]] auto alga_info() const -> const SpeciesInfo &;
    [[nodiscard]] auto fungus_info() const -> const SpeciesInfo &;
    [[nodiscard]] auto bacteria_info() const -> const SpeciesInfo &;

    [[nodiscard]] auto make_species_from_symbol(char symbol) const -> std::optional<std::unique_ptr<Organism>>;

private:
    void assert_info_types_correct() const;
    void assert_symbols_unique() const;
};
