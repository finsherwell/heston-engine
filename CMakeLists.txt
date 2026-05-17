cmake_minimum_required(VERSION 3.20)
project(HestonEngine VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-03 -march=native -Wall)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(Python3 COMPONENTS Development REQUIRED)

add_subdirectory(extern/pybind11)
add_subdirectory(src)
add_subdirectory(tests)