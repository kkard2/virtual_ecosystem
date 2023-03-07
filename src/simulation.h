#pragma once

#include <memory>

#include "map.h"
#include "random.h"

class Simulation {
private:
    std::unique_ptr<Random> m_random;
    std::vector<Map> m_maps;
    size_t m_current_map_index;

public:
    Simulation(
        Map starting_map,
        std::unique_ptr<Random> random = std::make_unique<Random>()
    );

public:
    [[nodiscard]] auto current_map() const -> const Map &;
    [[nodiscard]] auto current_map_index() const -> size_t;
    [[nodiscard]] auto total_maps() const -> size_t;
    [[nodiscard]] auto seed() const 

    auto step_forward() -> void;
    auto try_step_back() -> bool;
};
