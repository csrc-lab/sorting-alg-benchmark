#pragma once
#include "sort_algorithm.h"

class QuickSort : public SortAlgorithm {
public:
    void sort(std::vector<int> &data) override;
private:
    int pickPivot(int beg, int end);
    int partition(std::vector<int> &data, int beg, int end, int pivotIdx);
    void sort(std::vector<int> &data, int beg, int end);
    void swap(int &val1, int &val2);
};