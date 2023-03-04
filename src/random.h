#pragma once

#include <random>

class Random {
private:
    std::random_device m_random_device;

private:
    Random();
    ~Random() = default;

public:
    Random(const Random &) = delete;
    auto operator=(const Random &) -> Random & = delete;

public:
    static auto get(int32_t min, int32_t max) -> int32_t;

private:
    static auto instance() -> Random &;
};
