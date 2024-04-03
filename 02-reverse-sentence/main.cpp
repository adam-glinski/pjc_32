#include <algorithm>
#include <cctype>
#include <fmt/core.h>

std::string reversed_words(std::string words) {
    std::ranges::reverse(words);
    words += ' ';
    auto last_ws = words.begin();
    for (auto i = words.begin(); i != words.end(); i++) {
        if(isspace(*i)) {
            std::ranges::reverse(last_ws, i);
            last_ws = i + 1;
        }
    }
    return words;
}

auto main() -> int {
    fmt::println(
            "{}\n{}\n{}\n{}",
            reversed_words("Ala ma kota"),
            reversed_words("Ala"),
            reversed_words(""),
            reversed_words("1 2 3")
    );
}

