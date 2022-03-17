#include <random>

class Random {
public:
    static int get(int min, int max) {
        static std::random_device rnd;
        std::mt19937 rng(rnd());
        std::uniform_int_distribution<int> uni(min, max);
        return uni(rng);
    }
};