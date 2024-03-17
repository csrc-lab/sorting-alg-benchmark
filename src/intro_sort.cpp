#include "intro_sort.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "heap_sort.h"

IntroSort::IntroSort() {
    quickSort = new QuickSort();
    insertionSort = new InsertionSort();
    heapSort = new HeapSort();
}
IntroSort::~IntroSort() {
    delete quickSort;
    delete insertionSort;
    delete heapSort;
}

void IntroSort::sort(std::vector<int> &data) {
    int beg = 0, end = data.size() - 1;
    int depthLimit = 2 * log(end - beg);
    intro_sort(data, beg, end, depthLimit);
}

void IntroSort::intro_sort(std::vector<int> &data, int beg, int end, int depthLimit) {
    int size = end - beg;

    // if partition size is low then do insertion sort
    if (size < 16) {
        insertionSort->sort(data, beg, end);
        return;
    }

    // if the depth is zero use heapsort
    if (depthLimit == 0) {
        heapSort->sort(data);
        return;
    }
    int pivotIdx = quickSort->pickPivot(beg, end);
    int newPivotIdx = quickSort->partition(data, beg, end, pivotIdx);
    intro_sort(data, beg, newPivotIdx - 1, depthLimit - 1);
    intro_sort(data, newPivotIdx + 1, end, depthLimit - 1);

    return;
}