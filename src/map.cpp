#include "map.h"

#include <utility>

Map::Map(const Settings &settings, Size size, std::map<Position, std::unique_ptr<Organism>, PositionComparer> organisms)
    : m_settings(settings)
    , m_size(std::move(size))
    , m_organisms(std::move(organisms))
{
}

auto Map::settings() const -> const Settings & {
    return m_settings;
}

auto Map::size() const -> const Size & {
    return m_size;
}

auto Map::organisms() -> std::map<Position, std::unique_ptr<Organism>, PositionComparer> & {
    return m_organisms;
}

auto Map::update() -> void {
    for (auto &pair : m_organisms) {
        pair.second->update();
    }
}
