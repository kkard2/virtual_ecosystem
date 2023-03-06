#include "console_simulation_presenter.h"

void ConsoleSimulationPresenter::present(const Simulation &simulation) {
    std::cout << "Press h for help" << std::endl;
    std::cout << std::endl;
    std::cout << "Simulation step: " << simulation << std::endl;
}
