#pragma once
#include "sort_algorithm.h"
#include "intro_sort.h"

class InsertionSort : public SortAlgorithm {
public:
    void sort(std::vector<int> &data) override;
private:
    void sort(std::vector<int> &data, int beg, int end);
    friend class IntroSort;
    friend class TimSort;
};