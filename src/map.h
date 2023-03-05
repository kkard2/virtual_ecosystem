#pragma once

#include <map>
#include <optional>
#include <vector>

#include "organisms/organism.h"
#include "position.h"
#include "size.h"

// Fixes cyclic reference
class Organism;

class Map {
private:
    const Size m_size;
    std::map<Position, std::unique_ptr<Organism>, PositionComparer> m_organisms;

public:
    Map(Size size, std::map<Position, std::unique_ptr<Organism>, PositionComparer> organisms);

public:
    [[nodiscard]] auto size() const -> const Size &;
    [[nodiscard]] auto organisms() -> std::map<Position, std::unique_ptr<Organism>, PositionComparer> &;
};
