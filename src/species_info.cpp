#include "species_info.h"

#include <utility>
#include <sstream>

SpeciesInfo::SpeciesInfo(
    SpeciesType type, std::string name, char symbol, uint32_t health_min, uint32_t health_max, uint32_t offspring_cost,
    uint32_t meal_limit
)
    : m_type(type)
    , m_name(std::move(name))
    , m_symbol(symbol)
    , m_health_min(health_min)
    , m_health_max(health_max)
    , m_offspring_cost(offspring_cost)
    , m_meal_limit(meal_limit)
{
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

auto SpeciesInfo::health_min() const -> uint32_t {
    return m_health_min;
}

auto SpeciesInfo::health_max() const -> uint32_t {
    return m_health_max;
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
        << "  Health: " << health_min() << "-" << health_max() << std::endl
        << "  Offspring cost: " << offspring_cost() << std::endl
        << "  Meal limit: " << meal_limit();

    return ss.str();
}
