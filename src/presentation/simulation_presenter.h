#pragma once

#include "../simulation.h"
#include "../loading/map_loader_error.h"

class SimulationPresenter {
public:
    virtual void present(const Simulation &simulation) = 0;
    virtual void present_map_loader_error(const MapLoaderError &error) = 0;
    virtual void present_help_screen() = 0;
};
