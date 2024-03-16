#pragma once
#include <vector>

class SortAlgorithm {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortAlgorithm() {};
};