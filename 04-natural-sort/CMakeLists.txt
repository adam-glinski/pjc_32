set(CURRENT_TARGET natural-sort)

add_executable(${CURRENT_TARGET} 
    main.cpp
    natural_sort.cpp)

target_link_libraries(${CURRENT_TARGET} fmt)
