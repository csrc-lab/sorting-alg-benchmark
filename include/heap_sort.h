#pragma once
#include "sort_algorithm.h"
#include "intro_sort.h"

class HeapSort : public SortAlgorithm
{
public:
    void sort(std::vector<int> &data) override;
};