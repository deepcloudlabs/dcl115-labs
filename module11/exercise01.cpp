#include <iostream>
#include <generator>
#include <ranges>

std::generator<int> _3n_plus_1(int seed) {
    co_yield seed;
    while (seed != 1){
        if (seed %2 == 0)
            seed = seed / 2 ;
        else
            seed = 3 * seed + 1;
        co_yield seed;
    }
    co_yield 1;
}

int main() {
    for (const int next: _3n_plus_1(1'000'000) | std::views::take_while( [](int u) { return u>1;}))
        std::cout << next << ' ';
    std::cout << 1 << '\n';
    return 0;
}
