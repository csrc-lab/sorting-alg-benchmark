#include "heap_sort.h"
#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap

void HeapSort::sort(std::vector<int> &data) {
    std::make_heap(data.begin(), data.end());
    std::sort_heap(data.begin(), data.end());
}
