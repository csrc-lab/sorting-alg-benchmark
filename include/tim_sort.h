#pragma once
#include "sort_algorithm.h"

class InsertionSort;
class MergeSort;

class TimSort : public SortAlgorithm {
   public:
    void sort(std::vector<int> &data) override;

   private:
    void sort(std::vector<int> &data, int runSize);
    int calculateRunSize(int n);
    std::vector<int> splitIntoRuns(std::vector<int> &data);
    void sortRuns(std::vector<int> &data, std::vector<int> &runSizes);
    void mergeRuns(std::vector<int> &data, std::vector<int> &runSizes);

    InsertionSort *insertionSort;
    MergeSort *mergeSort;
};