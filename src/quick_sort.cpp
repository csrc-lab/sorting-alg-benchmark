#include "quick_sort.h"

void QuickSort::sort(std::vector<int> &data) {
    sort(data, 0, data.size()-1);
}

void QuickSort::sort(std::vector<int> &data, int beg, int end) {
    if (beg < end) {
        int pivotIdx = pickPivot(beg, end);
        int newPivotIdx = partition(data, beg, end, pivotIdx);
        sort(data, beg, newPivotIdx - 1);
        sort(data, newPivotIdx + 1, end);
    }
}
int QuickSort::pickPivot(int beg, int end) {
    return beg; // simplest implementation, which is pick head as pivot
}

int QuickSort::partition(std::vector<int> &data, int beg, int end, int pivotIdx)
{
    int pivotValue = data[pivotIdx];
    swap(data[pivotIdx], data[end]); // move pivot to the end
    int swapIdx = beg;
    for (int i = beg; i < end; i++) {
        if (data[i] < pivotValue) {
            swap(data[swapIdx], data[i]);
            swapIdx += 1;
        }
    }
    swap(data[swapIdx], data[end]);
    return swapIdx;
}

void QuickSort::swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}