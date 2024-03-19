#include "tim_sort.h"

#include <iostream>

#include "insertion_sort.h"
#include "merge_sort.h"

void TimSort::sort(std::vector<int> &data) {
    int n = data.size();

    std::vector<int> runSizes = splitIntoRuns(data);

    // std::cout << "Runs: ";
    // for (int i = 0; i < runSizes.size(); i++) {
    //     std::cout << runSizes[i] << " ";
    // }
    // std::cout << std::endl;

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
    int accIndex = 0;

    std::vector<int> currentRunSizes = runSizes;
    std::vector<int> nextRunSizes;
    while (runCount > 1) {
        accIndex = 0;
        for (int i = 0; i < runCount - 1; i += 2) {
            int run1Size = currentRunSizes[i];
            int run2Size = currentRunSizes[i + 1];

            mergeSort->merge(data, accIndex, accIndex + run1Size - 1,
                             accIndex + run1Size + run2Size - 1);

            nextRunSizes.push_back(run1Size + run2Size);
            accIndex += run1Size + run2Size;
        }
        runCount = nextRunSizes.size();

        // clear
        currentRunSizes.clear();
        currentRunSizes = nextRunSizes;
        nextRunSizes.clear();
    }
}