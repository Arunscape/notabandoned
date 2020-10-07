cmake_minimum_required(VERSION 3.11)
project(notabandoned)

# raylib-cpp
find_package(raylib-cpp 3.0.1 QUIET)
if (NOT raylib-cpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib-cpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG v3.0.1
  )
  FetchContent_GetProperties(raylib-cpp)
  if (NOT raylib-cpp_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib-cpp)
    set(BUILD_RAYLIB_CPP_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING             OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib-cpp_SOURCE_DIR} ${raylib-cpp_BINARY_DIR})
  endif()
endif()

add_executable(
    notabandoned
    src/main.cpp
)
set(raylib_VERBOSE 1)
target_link_libraries(notabandoned PUBLIC raylib raylib-cpp)