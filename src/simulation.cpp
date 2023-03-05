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

auto Simulation::step_forward() -> void {
    if (++m_current_map_index < m_maps.size()) {
        return;
    }

    auto &current_map = m_maps[m_current_map_index - 1];
    auto new_map = Map(current_map);

    for (auto &[position, organism] : new_map.organisms()) {
        organism->update();
    }

    for (auto &[position, organism] : new_map.organisms()) {
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
