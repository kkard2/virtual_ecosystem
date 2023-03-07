#include <iostream>
#include "simulation.h"

Simulation::Simulation(Map starting_map, std::unique_ptr<Random> random)
    : m_random(std::move(random))
    , m_maps()
    , m_current_map_index(0)
{
    m_maps.push_back(std::move(starting_map));
}

auto Simulation::current_map() const -> const Map & {
    return m_maps[m_current_map_index];
}

auto Simulation::current_map_index() const -> size_t {
    return m_current_map_index;
}

auto Simulation::total_maps() const -> size_t {
    return m_maps.size();
}

auto Simulation::seed() const -> uint32_t {
    return m_random->seed();
}

auto Simulation::step_forward() -> void {
    if (++m_current_map_index < m_maps.size()) {
        return;
    }

    auto &current_map = m_maps[m_current_map_index - 1];
    auto new_map = Map(current_map);

    auto organism_keys = std::vector<Position>();

    for (auto &[position, organism] : new_map.organisms()) {
        organism->update();
        organism_keys.push_back(position);
    }

    while (!organism_keys.empty()) {
        auto index = m_random->next(static_cast<size_t>(0), organism_keys.size() - 1);
        auto position = organism_keys[index];
        organism_keys.erase(organism_keys.begin() + static_cast<int32_t>(index));

        if (!new_map.organisms().contains(position)) {
            continue;
        }

        auto &organism = new_map.organisms()[position];
        auto context = ActionContext(*m_random, new_map, position);

        organism->perform_action(context);
    }

    m_maps.push_back(std::move(new_map));
}

auto Simulation::try_step_back() -> bool {
    if (m_current_map_index == 0) {
        return false;
    }

    m_current_map_index--;
    return true;
}
