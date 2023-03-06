#pragma once

#include <variant>

#include "map_loader_error.h"

#include "../map.h"
#include "../settings/settings.h"

class MapLoader {
private:
    const Settings &m_settings;

public:
    explicit MapLoader(const Settings &settings = Settings::default_settings());

public:
    [[nodiscard]] auto settings() const -> const Settings &;
    [[nodiscard]] auto load_map(const std::string &path) const -> std::variant<Map, MapLoaderError>;
};
