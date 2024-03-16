cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithmBenchmark)

# specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include directories for header files
include_directories(include)

# add subdirectories
add_subdirectory(src)

# add the executable
add_executable(SortingAlgorithmBenchmark src/main.cpp)
# link the executable to the SortingAlgorithmBenchmark library
target_link_libraries(SortingAlgorithmBenchmark SortingLib)
