#include "map_loader.h"

#include <fstream>
#include <string>

MapLoader::MapLoader(const Settings &settings)
    : m_settings(settings)
{
}

auto MapLoader::load_map(const std::string &path) const -> std::variant<Map, MapLoaderError> {
    auto file = std::ifstream(path);

    if (file.fail()) {
        return MapLoaderError::COULD_NOT_OPEN_FILE;
    }

    auto line = std::string();
    auto organisms = std::map<Position, std::unique_ptr<Organism>, PositionComparer>();

    int32_t x = 0;
    int32_t y = 0;

    int32_t max_x = 0;

    while (std::getline(file, line)) {
        for (auto &character : line) {

            if (character == ' ') {
                continue;
            }

            if (character == m_settings.empty_symbol()) {
                x++;

                if (x > max_x) {
                    max_x = x;
                }

                continue;
            }

            auto position = Position(x, y);
            auto organism = m_settings.make_species_from_symbol(character);

            if (!organism.has_value()) {
                return MapLoaderError::INVALID_SYMBOL;
            }

            organisms.emplace(position, std::move(organism.value()));
            x++;

            if (x > max_x) {
                max_x = x;
            }
        }

        x = 0;
        y++;
    }

    return Map(Size(static_cast<uint32_t>(max_x), static_cast<uint32_t>(y)), std::move(organisms));
}
