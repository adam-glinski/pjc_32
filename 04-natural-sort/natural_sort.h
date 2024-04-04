#pragma once
#include <fmt/core.h>
#include <string>
#include <vector>

namespace pjc {
enum class RETURN_TYPE {
    INVALID = -1,
    FALSE,
    TRUE,
    EQUAL
};
struct natural_sort {
    bool operator()(const std::string &a, const std::string &b) const;
};

std::vector<const char *> tokenise(const std::string &string);

RETURN_TYPE compare_int(const char *a, const char *b);
RETURN_TYPE compare_str(const char *a, const char *b);

template <typename T>
std::vector<T> &get_smaller_vector(std::vector<T> &a, std::vector<T> &b);
} // namespace pjc
