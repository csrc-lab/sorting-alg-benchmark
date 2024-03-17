#pragma once
#include "sort_algorithm.h"
#include "intro_sort.h"

class InsertionSort : public SortAlgorithm
{
public:
    void sort(std::vector<int> &data) override;
    friend class IntroSort;
private:
    void sort(std::vector<int> &data, int beg, int end);
};