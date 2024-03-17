#include <ctime>  //time
#include <iostream>
#include <memory>  //std::unique_ptr, std::make_unique
#include <vector>

#include "heap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

const int numbers = 100;

int main() {
    srand(time(NULL));

    std::vector<int> data;
    for (int i = 0; i < numbers; i++) {
        data.push_back(rand() % 100);
    }

    // std::unique_ptr<SortAlgorithm> sorter = std::make_unique<QuickSort>();
    // std::unique_ptr<SortAlgorithm> sorter = std::make_unique<HeapSort>();
    std::unique_ptr<SortAlgorithm> sorter = std::make_unique<MergeSort>();
    sorter->sort(data);
    for (int &ele : data) {
        std::cout << ele << " ";
    }
    return 0;
}