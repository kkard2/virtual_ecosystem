#include "random.h"

Random::Random() : m_random_device() {
}

auto Random::get(int32_t min, int32_t max) -> int32_t {
    if (min > max) {
        std::swap(min, max);
    }

    auto distribution = std::uniform_int_distribution<int32_t>(min, max);
    return distribution(instance().m_random_device);
}

auto Random::instance() -> Random & {
    static Random instance;
    return instance;
}
