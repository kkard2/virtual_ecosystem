#pragma once

#include <memory>

#include "input.h"
#include "../simulation.h"
#include "../presentation/simulation_presenter.h"
#include "../settings/settings.h"

class Application {
private:
    Input &m_input;
    SimulationPresenter &m_presenter;
    const Settings &m_settings;

    std::optional<uint64_t> m_seed;
    std::optional<std::filesystem::path> m_path;

    std::unique_ptr<Simulation> m_simulation;

public:
    Application(
        Input &input,
        SimulationPresenter &presenter,
        std::optional<uint64_t> seed = std::nullopt,
        std::optional<std::filesystem::path> path = std::nullopt,
        const Settings &settings = Settings::default_settings()
    );

public:
    auto run() -> void;
    auto loop() -> void;
};
