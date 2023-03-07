#pragma once

#include "simulation_presenter.h"
#include "../settings/settings.h"

class ConsoleSimulationPresenter : public SimulationPresenter {
private:
    const Settings &m_settings;

public:
    explicit ConsoleSimulationPresenter(const Settings &settings);

private:
    static auto clear_console() -> void;
    static auto present_species_stats(const std::string &name, char symbol, size_t amount, size_t alignment) -> void;

public:
    auto present(const Simulation &simulation) -> void override;
    auto present_map_loader_error(const MapLoaderError &error) -> void override;
    auto present_help_screen() -> void override;

private:
    auto present_map(const Simulation &simulation) const -> void;
    auto present_stats(const Simulation &simulation) const -> void;

    auto present_organism_symbol(
        const std::map<Position, std::unique_ptr<Organism>, PositionComparer> &organisms, size_t x, size_t y) const -> void;
};
