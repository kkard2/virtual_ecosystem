#pragma once

#include <map>
#include <memory>

#include "size.h"
#include "species_info.h"

class Settings {
private:
    const char m_corpse_symbol;
    const char m_empty_symbol;
    const SpeciesInfo &m_alga_info;
    const SpeciesInfo &m_fungus_info;
    const SpeciesInfo &m_bacteria_info;

public:
    // SAFETY: References must outlive this object.
    Settings(
        char corpse_symbol, char empty_symbol,
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
    [[nodiscard]] auto alga_info() const -> const SpeciesInfo &;
    [[nodiscard]] auto fungus_info() const -> const SpeciesInfo &;
    [[nodiscard]] auto bacteria_info() const -> const SpeciesInfo &;

private:
    void assert_info_types_correct() const;
    void assert_symbols_unique() const;
};
