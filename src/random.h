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

    auto next(int32_t min, int32_t max) -> int32_t;
    auto next(uint32_t min, uint32_t max) -> uint32_t;
    auto next(size_t min, size_t max) -> size_t;
};
