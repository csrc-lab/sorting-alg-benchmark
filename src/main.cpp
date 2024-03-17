#include <ctime>  //time
#include <iostream>
#include <memory>  //std::unique_ptr, std::make_unique
#include <vector>

#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "tim_sort.h"

const int numbers = 68;
const int max = 1000;

int main() {
    srand(time(NULL));

    std::vector<int> data;
    for (int i = 0; i < numbers; i++) {
        data.push_back(rand() % max);
    }

    // std::unique_ptr<SortAlgorithm> sorter = std::make_unique<QuickSort>();
    // std::unique_ptr<SortAlgorithm> sorter = std::make_unique<HeapSort>();
    // std::unique_ptr<SortAlgorithm> sorter = std::make_unique<MergeSort>();
    // std::unique_ptr<SortAlgorithm> sorter =
    // std::make_unique<InsertionSort>();
    std::unique_ptr<SortAlgorithm> sorter = std::make_unique<TimSort>();
    sorter->sort(data);
    std::cout << "Sorted data:\n";
    for (int &ele : data) {
        std::cout << ele << " ";
    }
    return 0;
}