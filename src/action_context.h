#pragma once

#include <optional>

#include "map.h"
#include "random.h"
#include "cell_type.h"

// Fixes cyclic reference
class Map;

class ActionContext {
private:
    Random &m_random;
    Map &m_map;
    const Position m_position;

public:
    // SAFETY: References must outlive this object.
    ActionContext(Random &random, Map &map, Position position);

public:
    [[nodiscard]] auto random() -> Random &;
    [[nodiscard]] auto map() -> Map &;
    [[nodiscard]] auto position() const -> const Position &;

    [[nodiscard]] auto neighbors() const -> std::vector<std::pair<Position, CellType>>;

    [[nodiscard]] auto neighbor_count(CellType type) const -> size_t;
    [[nodiscard]] auto random_neighbor(CellType type) const -> std::optional<Position>;
};
