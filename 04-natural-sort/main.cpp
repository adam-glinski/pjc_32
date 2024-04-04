#include <fmt/core.h>
#include "natural_sort.h"



auto main() -> int {
    // std::string test = "foo12bar13";
    // std::vector<std::string> files = {
    //     "file1",
    //     "file10",
    //     "file2",
    //     "file10test",
    //     "file10aaa"
    // };
    std::vector<std::string> files = {
        "File2.txt", "file1.txt", "file10.txt"
    };

    std::ranges::sort(files, pjc::natural_sort{});
    for(auto f : files)
        fmt::println("{}", f);
    // fmt::println("{}", static_cast<int>(pjc::compare_str("file-", "file")));
}
