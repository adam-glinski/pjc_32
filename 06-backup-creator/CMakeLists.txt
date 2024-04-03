set(CURRENT_TARGET backup-creator)
add_executable(${CURRENT_TARGET} main.cpp)
target_link_libraries(${CURRENT_TARGET} fmt)
