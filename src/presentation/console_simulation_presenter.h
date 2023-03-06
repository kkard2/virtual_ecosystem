#pragma once

#include "simulation_presenter.h"

class ConsoleSimulationPresenter : public SimulationPresenter {
public:
    void present(const Simulation &simulation) override;
};
