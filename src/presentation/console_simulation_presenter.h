#pragma once

#include "simulation_presenter.h"
#include "../settings/settings.h"

class ConsoleSimulationPresenter : public SimulationPresenter {
private:
    const Settings &m_settings;

public:
    explicit ConsoleSimulationPresenter(const Settings &settings);

private:
    static void clear_console();
    static void present_species_stats(const std::string &name, char symbol, size_t amount, size_t alignment);

public:
    void present(const Simulation &simulation) override;
    void present_map_loader_error(const MapLoaderError &error) override;

private:
    void present_map(const Simulation &simulation) const;
    void present_stats(const Simulation &simulation) const;
};
