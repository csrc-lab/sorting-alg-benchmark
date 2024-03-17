#pragma once
#include "sort_algorithm.h"

class MergeSort : public SortAlgorithm {
   public:
    void sort(std::vector<int> &data) override;

   private:
    void merge(std::vector<int> &data, int beg, int mid, int end);
    void sort(std::vector<int> &data, int beg, int end);

    friend class TimSort;
};