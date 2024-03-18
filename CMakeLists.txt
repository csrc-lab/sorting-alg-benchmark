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

# Google Benchmark
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory(external/benchmark)
target_link_libraries(SortingAlgorithmBenchmark benchmark::benchmark)
# link the executable to the SortingAlgorithmBenchmark library
target_link_libraries(SortingAlgorithmBenchmark SortingLib)
