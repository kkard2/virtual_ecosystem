cmake_minimum_required(VERSION 3.12)
project(virtual_ecosystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(virtual_ecosystem
    src/main.cpp
    src/position.cpp
    src/random.cpp
    src/size.cpp
    src/map.cpp
    src/action_context.cpp
    src/cell_type.cpp
    src/simulation.cpp

    src/control/console_input.cpp
    src/control/user_action.cpp

    src/loading/map_loader.cpp

    src/organisms/organism.cpp
    src/organisms/fungus.cpp
    src/organisms/bacteria.cpp
    src/organisms/alga.cpp

    src/presentation/console_simulation_presenter.cpp

    src/settings/species_info.cpp
    src/settings/settings.cpp
)
