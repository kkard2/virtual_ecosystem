#pragma once

#include <random>

class Random {
private:
    const uint32_t m_seed;
    std::default_random_engine m_engine;

public:
    Random();
    explicit Random(uint32_t seed);

    Random(const Random &) = delete;
    auto operator=(const Random &) -> Random & = delete;
    ~Random() = default;

public:
    [[nodiscard]] auto seed() const -> uint32_t;

    auto get(int32_t min, int32_t max) -> int32_t;
};
