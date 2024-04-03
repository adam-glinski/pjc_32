set(CURRENT_TARGET reverse-sentence)
add_executable(${CURRENT_TARGET} main.cpp)
target_link_libraries(${CURRENT_TARGET} fmt)
