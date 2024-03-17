#include "tim_sort.h"

#include <iostream>

#include "insertion_sort.h"
#include "merge_sort.h"

void TimSort::sort(std::vector<int> &data) {
    int n = data.size();

    std::vector<int> runSizes = splitIntoRuns(data);

    std::cout << "Runs: ";
    for (int i = 0; i < runSizes.size(); i++) {
        std::cout << runSizes[i] << " ";
    }
    std::cout << std::endl;

    sortRuns(data, runSizes);
    mergeRuns(data, runSizes);
}

int TimSort::calculateRunSize(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

std::vector<int> TimSort::splitIntoRuns(std::vector<int> &data) {
    int n = data.size();
    int runSize = calculateRunSize(n);
    std::vector<int> runs;
    runs.reserve(n / runSize + 1);

    int beg = 0;
    while (beg < n) {
        int end = std::min(beg + runSize, n);
        runs.push_back(end - beg);
        beg = end;
    }

    return runs;
}

void TimSort::sortRuns(std::vector<int> &data, std::vector<int> &runSizes) {
    int accIndex = 0;
    for (int i = 0; i < runSizes.size(); i++) {
        int runSize = runSizes[i];
        if (runSize > 1) {
            insertionSort->sort(data, accIndex, accIndex + runSize);
        }
        accIndex += runSize;
    }
}

void TimSort::mergeRuns(std::vector<int> &data, std::vector<int> &runSizes) {
    int runCount = runSizes.size();
    int accIndex = runSizes[0];
    for (int i = 1; i < runCount; i++) {
        int runSize = runSizes[i];
        if (runSize > 1) {
            mergeSort->merge(data, 0, accIndex - 1, accIndex + runSize - 1);
        }
        accIndex += runSize;
    }
}