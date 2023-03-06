#pragma once

#include "../simulation.h"

class SimulationPresenter {
public:
    virtual void present(const Simulation &simulation) = 0;
};
