#include "natural_sort.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <fmt/ranges.h>

bool pjc::natural_sort::operator()(const std::string &a, const std::string &b) const  {
    auto tokenised_a = tokenise(a);
    auto tokenised_b = tokenise(b);
    for(int i = 0; i < get_smaller_vector(tokenised_a, tokenised_b).size(); i++) {
        auto int_comp = compare_int(tokenised_a[i], tokenised_b[i]);
        if (int_comp != RETURN_TYPE::INVALID)
            switch (int_comp) {
                case pjc::RETURN_TYPE::TRUE:
                case pjc::RETURN_TYPE::FALSE:
                    return static_cast<bool>(int_comp);
                default:
                    break;
            }
        else {
            auto str_comp = compare_str(tokenised_a[i], tokenised_b[i]);
            switch (str_comp) {
                case pjc::RETURN_TYPE::TRUE:
                case pjc::RETURN_TYPE::FALSE:
                    return static_cast<bool>(str_comp);
                default:
                    break;
            }
        }
    }
    return b.size() - a.size();
}

pjc::RETURN_TYPE pjc::compare_int(const char *a, const char *b) {
    int ia;
    int ib;
    try {
        ia = std::stoi(a);
        ib = std::stoi(b);
    } catch (std::invalid_argument const &e) {
        return RETURN_TYPE::INVALID;
    }

    // If a < b we wanna swap, else dont do anything
    return ia < ib ? RETURN_TYPE::TRUE : RETURN_TYPE::FALSE;
}

pjc::RETURN_TYPE pjc::compare_str(const char *a, const char *b) {
    std::vector<std::string> tmp = {a, b};
    std::transform(tmp[0].begin(), tmp[0].end(), tmp[0].begin(), tolower);
    std::transform(tmp[1].begin(), tmp[1].end(), tmp[1].begin(), tolower);
    if(tmp[0] == tmp[1])
        return RETURN_TYPE::EQUAL;
    std::ranges::sort(tmp);
    return tmp[0].c_str() == a ? RETURN_TYPE::TRUE : RETURN_TYPE::FALSE;
}

std::vector<const char *> pjc::tokenise(const std::string &string) {
    if (string.size() == 0)
        return {};
    std::vector<const char *> result = {};
    std::string builder{string[0]};
    for (int i = 1; i < string.size(); i++) {
        char current = string[i];
        auto prev = builder.back();
        if ((std::isalpha(current) && std::isalpha(prev)) ||
            (std::isdigit(current) && std::isdigit(prev)))
            builder.push_back(current);
        else {
            result.push_back(strdup(builder.c_str()));
            builder.clear();
            builder.push_back(current);
        }
    }
    result.push_back(strdup(builder.c_str())); // Push the last token
    fmt::println("Tokenised: {}", result);
    return result;
}

template <typename T>
std::vector<T>& pjc::get_smaller_vector(std::vector<T> &a, std::vector<T> &b) {
    return a.size() < b.size() ? a : b;
}
