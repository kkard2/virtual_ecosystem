#include "console_simulation_presenter.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif // _WIN32

ConsoleSimulationPresenter::ConsoleSimulationPresenter(const Settings &settings)
    : m_settings(settings)
{
}

void ConsoleSimulationPresenter::clear_console() {
#if defined(_WIN32)
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
#elif defined(__linux__)
    std::cout << "\x1B[2J\x1B[H";
#else
#error "Unsupported platform"
#endif
}

void ConsoleSimulationPresenter::present_species_stats(
    const std::string &name, char symbol, size_t amount, size_t alignment
) {
    std::cout
        << std::right << std::setw(static_cast<int32_t>(alignment)) << name
        << ' ' << symbol
        << " : " << amount
        << std::endl;
}

void ConsoleSimulationPresenter::present(const Simulation &simulation) {
    clear_console();

    std::cout << "Enter 'h' for help or 'q' to quit" << std::endl;
    std::cout << "Seed: " << simulation.seed() << std::endl;
    std::cout << std::endl;
    std::cout << "Simulation step: " << simulation.current_map_index();

    if (simulation.current_map_index() < simulation.total_maps() - 1) {
        std::cout << " of " << simulation.total_maps() - 1;
    }

    std::cout << std::endl << std::endl;
    present_map(simulation);
    std::cout << std::endl;
    present_stats(simulation);
    std::cout << std::endl;
}

void ConsoleSimulationPresenter::present_map_loader_error(const MapLoaderError &error) {
    std::cout << "Error: ";

    switch (error) {
        case MapLoaderError::COULD_NOT_OPEN_FILE:
            std::cout << "Could not open file";
            break;
        case MapLoaderError::INVALID_SYMBOL:
            std::cout << "Invalid symbol in the file";
            break;
    }

    std::cout << std::endl;
    std::cin.get();
}

auto ConsoleSimulationPresenter::present_help_screen() -> void {
    clear_console();
    std::cout << "Enter 'h' for help" << std::endl;
    std::cout << "Enter 'q' to quit" << std::endl;
    std::cout << "Enter '.' to go to the next step" << std::endl;
    std::cout << "Enter ',' to go to the previous step" << std::endl;
    std::cout << "Enter '<number>.' to go forward <number> steps" << std::endl;
    std::cout << "Enter '<number>,' to go backward <number> steps" << std::endl;
    std::cout << std::endl;
    std::cout << "Press enter to exit this screen..." << std::endl;
    std::cin.get();
}

void ConsoleSimulationPresenter::present_map(const Simulation &simulation) const {
    const auto &map = simulation.current_map();
    const auto &organisms = map.organisms();
    const auto &size = map.size();

    for (size_t y = 0; y < size.height(); y++) {
        for (size_t x = 0; x < size.width(); x++) {
            present_organism_symbol(organisms, x, y);
        }

        std::cout << std::endl;
    }
}

void ConsoleSimulationPresenter::present_organism_symbol(
    const std::map<Position, std::unique_ptr<Organism>, PositionComparer> &organisms, size_t x, size_t y
) const {
    auto position = Position(static_cast<int32_t>(x), static_cast<int32_t>(y));

    if (organisms.contains(position)) {
        const auto &organism = organisms.at(position);

        if (!organism->is_alive()) {
            std::cout << m_settings.corpse_symbol();
        } else {
            std::cout << organism->info().symbol();
        }
    } else {
        std::cout << m_settings.empty_symbol();
    }

    std::cout << ' ';
}

void ConsoleSimulationPresenter::present_stats(const Simulation &simulation) const {
    const auto &map = simulation.current_map();
    const auto &organisms = map.organisms();

    auto species_stats = std::unordered_map<CellType, size_t> {
        {CellType::ALGA, 0},
        {CellType::BACTERIA, 0},
        {CellType::FUNGUS, 0},
        {CellType::CORPSE, 0},
    };

    for (const auto &[position, organism] : organisms) {
        if (!organism->is_alive()) {
            species_stats[CellType::CORPSE]++;
            continue;
        }

        auto cell_type = cell_type_from_species_type(organism->info().type());
        species_stats[cell_type]++;
    }

    size_t alignment = 0;
    alignment = std::max(alignment, m_settings.alga_info().name().size());
    alignment = std::max(alignment, m_settings.bacteria_info().name().size());
    alignment = std::max(alignment, m_settings.fungus_info().name().size());
    alignment = std::max(alignment, m_settings.corpse_name().size());

    present_species_stats(
        m_settings.alga_info().name(), m_settings.alga_info().symbol(),
        species_stats[CellType::ALGA], alignment
    );
    present_species_stats(
        m_settings.fungus_info().name(), m_settings.fungus_info().symbol(),
        species_stats[CellType::FUNGUS], alignment
    );
    present_species_stats(
        m_settings.bacteria_info().name(), m_settings.bacteria_info().symbol(),
        species_stats[CellType::BACTERIA], alignment
    );
    present_species_stats(
        m_settings.corpse_name(), m_settings.corpse_symbol(),
        species_stats[CellType::CORPSE], alignment
    );
}
