#pragma once
#include <vector>
#include <string>

class SortAlgorithm {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortAlgorithm() {};
};