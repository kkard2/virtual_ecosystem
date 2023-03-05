#pragma once

#include <map>
#include <optional>
#include <vector>

#include "organism.h"
#include "position.h"
#include "settings.h"
#include "size.h"

class Map {
private:
    const Settings &m_settings;
    const Size m_size;
    std::map<Position, std::unique_ptr<Organism>, PositionComparer> m_organisms;

public:
    // SAFETY: References must outlive this object.
    Map(const Settings &settings, Size size, std::map<Position, std::unique_ptr<Organism>, PositionComparer> organisms);

public:
    [[nodiscard]] auto settings() const -> const Settings &;
    [[nodiscard]] auto size() const -> const Size &;

    [[nodiscard]] auto organisms() -> std::map<Position, std::unique_ptr<Organism>, PositionComparer> &;

    auto update() -> void;
};
