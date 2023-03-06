#include "map.h"

#include <utility>

Map::Map(Size size, std::map<Position, std::unique_ptr<Organism>, PositionComparer> organisms)
    : m_size(std::move(size))
    , m_organisms(std::move(organisms))
{
}

Map::Map(const Map &map) : m_size(map.m_size) {
    for (auto &[position, organism] : map.m_organisms) {
        m_organisms[position] = organism->clone();
    }
}

auto Map::size() const -> const Size & {
    return m_size;
}

auto Map::organisms() -> std::map<Position, std::unique_ptr<Organism>, PositionComparer> & {
    return m_organisms;
}

auto Map::organisms() const -> const std::map<Position, std::unique_ptr<Organism>, PositionComparer> & {
    return m_organisms;
}
