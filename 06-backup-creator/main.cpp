#include <filesystem>
#include <fmt/core.h>
#include <fmt/ranges.h>

#define DEBUG
namespace fs = std::filesystem;

#ifdef DEBUG
#define LOG(x, ...) fmt::println(x, __VA_ARGS__)
#else
#define LOG(x, ...)
#endif

void copy_directory(const fs::path &src, const fs::path &dest) {
    fs::create_directory(dest);
    for (const auto &entry : fs::directory_iterator(src)) {
        const auto &src_path = entry.path();
        std::string new_filename = src_path.stem().c_str() + std::string("-backup") + src_path.extension().c_str();
        const auto &dest_path = dest / new_filename;
        if (fs::is_directory(src_path)) {
            LOG("Copying subdir: {} to {}", src_path.c_str(), dest_path.c_str());
            copy_directory(src_path, dest_path);
        } else {
            LOG("Copying file: {} to {}", src_path.c_str(), dest_path.c_str());
            fs::copy_file(src_path, dest_path, fs::copy_options::overwrite_existing);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fmt::println("Invalid number of arguments!\n \
        Correct usage: backup-creator <SOURCE> <DESTINATION>");
        return EXIT_FAILURE;
    }
    auto source = fs::path(argv[1]);
    auto destination = fs::path(argv[2]);
    if (!fs::exists(source)) {
        fmt::println("Invalid source path!");
        return EXIT_FAILURE;
    }
    copy_directory(source, destination);
    return EXIT_SUCCESS;
}
