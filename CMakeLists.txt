cmake_minimum_required(VERSION 3.14)
project(untitled1)

add_subdirectory(di)

set(CMAKE_CXX_STANDARD 17)
add_executable(untitled1 main.cpp)
target_link_libraries(untitled1 PRIVATE Boost.DI)