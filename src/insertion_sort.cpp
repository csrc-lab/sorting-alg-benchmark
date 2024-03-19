#include "insertion_sort.h"

void InsertionSort::sort(std::vector<int> &data) {
    sort(data, 0, data.size() - 1);
}

void InsertionSort::sort(std::vector<int> &data, int beg, int end) {
    for (int i = beg + 1; i <= end; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= beg && data[j] > key) {
            data[j + 1] = data[j];
            j -= 1;
        }
        data[j + 1] = key;
    }
}
