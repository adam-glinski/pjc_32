set(CURRENT_TARGET text-formatting)
add_executable(${CURRENT_TARGET} main.cpp)
target_link_libraries(${CURRENT_TARGET} fmt)

