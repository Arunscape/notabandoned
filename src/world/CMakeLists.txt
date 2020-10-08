add_library(
    world
    chunk.cpp
    block.cpp
)
target_link_libraries(world raylib raylib-cpp)
