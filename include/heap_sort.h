#pragma once
#include "sort_algorithm.h"

class HeapSort : public SortAlgorithm
{
public:
    void sort(std::vector<int> &data) override;
};