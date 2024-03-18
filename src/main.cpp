#include <ctime>  //time
#include <iostream>
#include <fstream> //std::ifstream
#include <memory>  //std::unique_ptr, std::make_unique
#include <vector>
#include <string>

#include "benchmark/benchmark.h"

#include "sort_algorithm.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "intro_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "tim_sort.h"

const int numbers = 68;
const int max = 1000;
const int ITERATIONS = 10;

std::vector<int> loadData(const std::string &filename, const int size) {
    try {
        std::vector<int> data;
        std::string concatFilename = "../data/" + filename + "/" + std::to_string(size) + ".txt";
        std::ifstream file(concatFilename);
        int value;
        while (file >> value) {
            data.push_back(value);
        }
        std::cout << "Data loaded from " << concatFilename << std::endl;
        std::cout << "file size: " << data.size() << " elements\n" << std::endl;
        return data;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return std::vector<int>();
    }
}

template <typename SortAlgorithm>
static void benchmarkSort(benchmark::State &state, const std::vector<int> &data) {
    for (auto _ : state) { // run multiple times and report the average time
        std::vector<int> copy(data);
        SortAlgorithm sorter;
        sorter.sort(copy);
    }
}

template <typename SortAlgorithm>
void registerBenchmark(const std::vector<int> &data, const std::string &name) {
    benchmark::RegisterBenchmark(name.c_str(), benchmarkSort<SortAlgorithm>, data)->Iterations(ITERATIONS);
}

int main(int argc, char **argv) {
    std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000};
    if (argc > 1) {
        std::string filename = argv[1];
        int size = std::stoi(argv[2]);
        std::vector<int> data = loadData(filename, size);
        registerBenchmark<InsertionSort>(data, "InsertionSort");
        registerBenchmark<HeapSort>(data, "HeapSort");
        registerBenchmark<IntroSort>(data, "IntroSort");
        registerBenchmark<MergeSort>(data, "MergeSort");
        registerBenchmark<QuickSort>(data, "QuickSort");
        benchmark::RunSpecifiedBenchmarks();
        std::cout << "----------------------------------------\n";
        std::cout << "⬆️  Benchmarking with " << size << " elements at " << filename << " distribution ⬆️\n";
    } else {
        std::cout << "No input file provided\n";
    }
    return 0;
}