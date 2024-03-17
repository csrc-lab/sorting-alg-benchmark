#pragma once
#include "sort_algorithm.h"

class InsertionSort : public SortAlgorithm
{
public:
    void sort(std::vector<int> &data) override;
private:
    void sort(std::vector<int> &data, int beg, int end);

    //TODO: add introsort as a friend class
};