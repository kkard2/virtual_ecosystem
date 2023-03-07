#include <iostream>

#include "simulation.h"
#include "loading/map_loader.h"
#include "presentation/console_simulation_presenter.h"
#include "control/application.h"
#include "control/console_input.h"

int main() {
    const auto &settings = Settings::default_settings();
    auto input = ConsoleInput();
    auto presenter = ConsoleSimulationPresenter(settings);

    auto app = Application(input, presenter, std::nullopt, std::nullopt, settings);
    app.run();
}
