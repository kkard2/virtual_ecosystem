#include "species_info.h"

#include <utility>
#include <sstream>

SpeciesInfo::SpeciesInfo(
        SpeciesType type, std::string name, char symbol, uint32_t age_min, uint32_t age_max, uint32_t offspring_cost,
        uint32_t meal_limit
)
    : m_type(type)
    , m_name(std::move(name))
    , m_symbol(symbol)
    , m_age_min(age_min)
    , m_age_max(age_max)
    , m_offspring_cost(offspring_cost)
    , m_meal_limit(meal_limit)
{
    if (age_min > age_max) {
        throw std::invalid_argument("age_min must be less than or equal to age_max");
    }

    if (offspring_cost > meal_limit) {
        throw std::invalid_argument("offspring_cost must be less than or equal to meal_limit");
    }
}

auto SpeciesInfo::default_alga() -> const SpeciesInfo & {
    static const auto info = SpeciesInfo(
        SpeciesType::ALGA, "Alga", '*', 5, 10, 2, 6
    );

    return info;
}

auto SpeciesInfo::default_fungus() -> const SpeciesInfo & {
    static const auto info = SpeciesInfo(
        SpeciesType::FUNGUS, "Fungus", '#', 40, 60, 3, 30
    );

    return info;
}

auto SpeciesInfo::default_bacteria() -> const SpeciesInfo & {
    static const auto info = SpeciesInfo(
        SpeciesType::BACTERIA, "Bacteria", 'B', 25, 40, 3, 10
    );

    return info;
}

auto SpeciesInfo::type() const -> SpeciesType {
    return m_type;
}

auto SpeciesInfo::name() const -> const std::string & {
    return m_name;
}

auto SpeciesInfo::symbol() const -> char {
    return m_symbol;
}

auto SpeciesInfo::age_min() const -> uint32_t {
    return m_age_min;
}

auto SpeciesInfo::age_max() const -> uint32_t {
    return m_age_max;
}

auto SpeciesInfo::offspring_cost() const -> uint32_t {
    return m_offspring_cost;
}

auto SpeciesInfo::meal_limit() const -> uint32_t {
    return m_meal_limit;
}

std::string SpeciesInfo::to_string() const {
    std::stringstream ss;
    ss
        << name() << " (" << symbol() << "):" << std::endl
        << "  Age: " << age_min() << "-" << age_max() << std::endl
        << "  Offspring cost: " << offspring_cost() << std::endl
        << "  Meal limit: " << meal_limit();

    return ss.str();
}
