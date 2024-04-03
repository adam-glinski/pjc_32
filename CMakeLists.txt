cmake_minimum_required(VERSION 3.5)
project(pjc_32)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
# include_directories(/opt/homebrew/include)
# link_directories(/opt/homebrew/lib)
include(fetchcontent)

fetchcontent_declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG  10.2.1
)

fetchcontent_makeavailable(fmt)

# Subdirectories
add_subdirectory(06-backup-creator)
add_subdirectory(05-text-chunking)
add_subdirectory(04-natural-sort)
add_subdirectory(03-text-formatting)
add_subdirectory(02-reverse-sentence)
add_subdirectory(01-box-print)
add_subdirectory(00-template)

# add_executable(${PROJECT_NAME} ${files})
# target_link_libraries(${PROJECT_NAME} fmt)

