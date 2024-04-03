#include <vector>
#include <fmt/core.h>
#include <fmt/format.h>


auto main() -> int {
    // Part 1
    auto triple_print = [](auto x) -> void {
        fmt::println("({}) ({}) ({})", x, x, x);
    };

    triple_print(13);
    triple_print("hello");

    // Part 2
    fmt::println("The simplest C++ program is: \"auto main() -> int {{ }}\"");

    // Part 3
    std::vector<int> test = {1, 7, 1, 3, 7};
    for (auto i : test) {
        fmt::print("{}", fmt::format("{} | ", i));
    }
}
