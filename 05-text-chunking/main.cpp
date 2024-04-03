#include <fmt/core.h>
#include <fmt/ranges.h>
#include <ranges>
#include <set>
#include <vector>

// TODO: Refactor (surely)
template <typename T> 
std::vector<std::vector<std::ranges::range_value_t<T>>> chunk(const T &tab, int n) {
    using type = std::ranges::range_value_t<T>;
    std::vector<std::vector<type>> result{};
    std::vector<type> vec_builder{};
    int element_counter = 1;
    // Could be done better but cba
    for (auto i = tab.begin(); i != tab.end(); i++) {
        if (element_counter % (n + 1) == 0) { // + 1 cuz we want to include the nth element in the current chunk
            result.push_back(vec_builder);
            element_counter = 1;
            vec_builder.clear();
            i--; //compensate for the used iteration
        } else {
            vec_builder.push_back(*i);
            element_counter++;
        }
    }
    result.push_back(vec_builder); // add the leftover chunk
    return result;
}

int main() {
    auto v1 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto v2 = std::vector<std::string>{"a", "b", "c", "d", "e", "f"};
    auto v3 = std::set<float>{1.41, 1.61, 1.73, 2.72, 3.14};

    auto v1by3 = chunk(v1, 3);
    auto v1by2 = chunk(v1, 2);

    auto v2by5 = chunk(v2, 5);
    auto v2by1 = chunk(v2, 1);

    auto v3by2 = chunk(v3, 2);
    auto v3by3 = chunk(v3, 3);

    fmt::println("{}", v1by3);
    fmt::println("{}", v1by2);
    fmt::println("{}", v2by5);
    fmt::println("{}", v2by1);
    fmt::println("{}", v3by2);
    fmt::println("{}", v3by3);
}
