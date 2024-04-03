#include <fmt/core.h>
#include <string>
#include <vector>

void boxPrint(std::vector<std::string> words, const char outline = '#') {
    // Not worth doing tbh too stimple
}

auto main() -> int {
    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmmm", ""});
    boxPrint({"", "", ""});
}

