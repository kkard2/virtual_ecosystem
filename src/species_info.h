#pragma once

#include <cstdint>
#include <string>

#include "species_type.h"
#include "display.h"

struct SpeciesInfo : public Display {
private:
    const SpeciesType m_type;
    const std::string m_name;
    const char m_symbol;
    const uint32_t m_age_min;
    const uint32_t m_age_max;
    const uint32_t m_offspring_cost;
    const uint32_t m_meal_limit;

public:
    SpeciesInfo(
            SpeciesType type, std::string name, char symbol, uint32_t age_min, uint32_t age_max,
            uint32_t offspring_cost, uint32_t meal_limit
    );

    SpeciesInfo(const SpeciesInfo &) = delete;
    auto operator=(const SpeciesInfo &) -> SpeciesInfo & = delete;

    ~SpeciesInfo() = default;

public:
    [[nodiscard]] static auto default_alga() -> const SpeciesInfo &;
    [[nodiscard]] static auto default_fungus() -> const SpeciesInfo &;
    [[nodiscard]] static auto default_bacteria() -> const SpeciesInfo &;

public:
    [[nodiscard]] auto type() const -> SpeciesType;
    [[nodiscard]] auto name() const -> const std::string &;
    [[nodiscard]] auto symbol() const -> char;
    [[nodiscard]] auto age_min() const -> uint32_t;
    [[nodiscard]] auto age_max() const -> uint32_t;
    [[nodiscard]] auto offspring_cost() const -> uint32_t;
    [[nodiscard]] auto meal_limit() const -> uint32_t;

public:
    [[nodiscard]] std::string to_string() const override;
};
