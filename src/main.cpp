#include "quick_sort.h"
#include "heap_sort.h"
#include<iostream>
#include <vector>
#include <memory> //std::unique_ptr, std::make_unique

int main() {
    std::vector<int> data = {8,10,6,3,1,2,7,5,9};
    // std::unique_ptr<SortAlgorithm> sorter = std::make_unique<QuickSort>();
    std::unique_ptr<SortAlgorithm> sorter = std::make_unique<HeapSort>();
    sorter->sort(data);
    for (int &ele : data) {
        std::cout << ele << " ";
    }
    return 0;
}