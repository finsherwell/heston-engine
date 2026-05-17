#pragma once
#include <random>

struct RNG {
    std::mt19937_64 engine;
    std::normal_distribution<double> norm{0.0, 1.0};

    explicit RNG(uint64_t seed = 42) : engine(seed) {}

    std::pair<double, double> next_antithetic() {
        double z = norm(engine);
        return {z, -z};
    }
};