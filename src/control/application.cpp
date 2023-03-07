#include "application.h"

#include <utility>

#include "../loading/map_loader.h"

Application::Application(
    Input &input,
    SimulationPresenter &presenter,
    std::optional<uint64_t> seed,
    std::optional<std::filesystem::path> path,
    const Settings &settings
)
    : m_input(input)
    , m_presenter(presenter)
    , m_seed(seed)
    , m_path(std::move(path))
    , m_settings(settings)
{
}

auto Application::run() -> void {
    if (!m_seed.has_value()) {
        m_seed = m_input.read_seed();
    }

    std::unique_ptr<Random> random;

    if (m_seed.has_value()) {
        random = std::make_unique<Random>(*m_seed);
    } else {
        random = std::make_unique<Random>();
    }

    if (!m_path.has_value()) {
        m_path = m_input.read_path();
    }

    auto loader = MapLoader(m_settings);

    auto starting_map = loader.load_map(m_path->string());

    if (starting_map.index() == 1) {
        m_presenter.present_map_loader_error(std::get<MapLoaderError>(starting_map));
        return;
    }

    m_simulation = std::make_unique<Simulation>(std::get<Map>(starting_map), std::move(random));

    loop();
}

auto Application::loop() -> void {
    auto action = std::optional<UserAction>();

    while (true) {
        m_presenter.present(*m_simulation);

        action = m_input.read_action();
        
        if (!action.has_value()) {
            continue;
        }

        switch (action->type()) {
            case UserActionType::INVALID:
                break;
            case UserActionType::HELP:
                // TODO:
                break;
            case UserActionType::QUIT:
                return;
            case UserActionType::STEP_FORWARD:
                for (size_t i = 0; i < action->count(); ++i) {
                    m_simulation->step_forward();
                }
                break;
            case UserActionType::STEP_BACK:
                for (size_t i = 0; i < action->count(); ++i) {
                    if (!m_simulation->try_step_back()) {
                        break;
                    }
                }
                break;
        }
    }
}
