#pragma once
#include "sort_algorithm.h"

class IntroSort : public SortAlgorithm
{
public:
    void sort(std::vector<int> &data) override;
};