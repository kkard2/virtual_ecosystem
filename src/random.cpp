#include "random.h"

Random::Random() : Random(std::random_device()()) {
}

Random::Random(uint32_t seed)
    : m_seed(seed)
    , m_engine(seed)
{
}

auto Random::seed() const -> uint32_t {
    return m_seed;
}

auto Random::next(int32_t min, int32_t max) -> int32_t {
    if (min > max) {
        std::swap(min, max);
    }

    auto distribution = std::uniform_int_distribution<int32_t>(min, max);
    return distribution(m_engine);
}

auto Random::next(size_t min, size_t max) -> size_t {
    if (min > max) {
        std::swap(min, max);
    }

    auto distribution = std::uniform_int_distribution<size_t>(min, max);
    return distribution(m_engine);
}
