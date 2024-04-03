#include <fmt/core.h>
#include "natural_sort.h"


static std::vector<std::string> files = {
        "file1",
        "file10",
        "file2",
    };

auto main() -> int {
    // std::string test = "foo12bar13";
    // std::vector<std::string> files = {
    //     "file1",
    //     "file10",
    //     "file2",
    // };

    //std::ranges::sort(files.begin(), files.end(), pjc::natural_sort());
    std::ranges::sort(files, pjc::natural_sort{});
    // for(auto s : pjc::tokenise(test))
    //     fmt::println("{}", s);
    // fmt::println("{}", (int)pjc::compare_str("a", "b"));
    for(auto f : files)
        fmt::println("{}", f);
}
