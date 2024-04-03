set(CURRENT_TARGET box-print)
add_executable(${CURRENT_TARGET} main.cpp)
target_link_libraries(${CURRENT_TARGET} fmt)
