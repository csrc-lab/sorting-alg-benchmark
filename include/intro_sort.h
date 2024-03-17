#pragma once
#include "sort_algorithm.h"
#include "insertion_sort.h"

class QuickSort;
class HeapSort;
class InsertionSort;

class IntroSort : public SortAlgorithm {
public:
    void sort(std::vector<int> &data) override;
    IntroSort();
    ~IntroSort();
private:
    void intro_sort(std::vector<int> &data, int beg, int end, int depthLimit);
    InsertionSort *insertionSort;
    HeapSort *heapSort;
    QuickSort *quickSort;
};