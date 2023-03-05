#include "action_context.h"

ActionContext::ActionContext(Random &random, Map &map, Position position)
    : m_random(random)
    , m_map(map)
    , m_position(std::move(position))
{
}

auto ActionContext::random() -> Random & {
    return m_random;
}

auto ActionContext::map() -> Map & {
    return m_map;
}

auto ActionContext::position() const -> const Position & {
    return m_position;
}

auto ActionContext::neighbors() const -> std::vector<std::pair<Position, CellType>> {
    auto neighbors = std::vector<std::pair<Position, CellType>>();
    neighbors.reserve(8);

    for (int32_t x = -1; x <= 1; x++) {
        for (int32_t y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) {
                continue;
            }

            auto neighbor = Position(m_position.x() + x, m_position.y() + y);

            if (!m_map.size().contains(neighbor)) {
                neighbors.emplace_back(neighbor, CellType::WALL);
                continue;
            }

            if (!m_map.organisms().contains(neighbor)) {
                neighbors.emplace_back(neighbor, CellType::EMPTY);
                continue;
            }

            auto &organism = m_map.organisms().at(neighbor);

            if (!organism->is_alive()) {
                neighbors.emplace_back(neighbor, CellType::CORPSE);
                continue;
            }

            neighbors.emplace_back(neighbor, cell_type_from_species_type(organism->info().type()));
        }
    }

    return neighbors;
}

auto ActionContext::neighbor_count(CellType type) const -> size_t {
    auto neighbors_collection = neighbors();

    return std::count_if(neighbors_collection.begin(), neighbors_collection.end(), [type](const auto &neighbor) {
        return neighbor.second == type;
    });
}

auto ActionContext::random_neighbor(CellType type) const -> std::optional<Position> {
    auto neighbors_collection = neighbors();

    auto result = std::vector<Position>();
    result.reserve(neighbors_collection.size());

    for (const auto &neighbor : neighbors_collection) {
        if (neighbor.second == type) {
            result.push_back(neighbor.first);
        }
    }

    if (result.empty()) {
        return std::nullopt;
    }

    return result[m_random.next(static_cast<size_t>(0), result.size() - 1)];
}
