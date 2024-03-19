#include "merge_sort.h"

void MergeSort::sort(std::vector<int> &data) { sort(data, 0, data.size() - 1); }

void MergeSort::sort(std::vector<int> &data, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        sort(data, beg, mid);
        sort(data, mid + 1, end);
        merge(data, beg, mid, end);
    }
}

// TODO: Galloping mode for time sort
void MergeSort::merge(std::vector<int> &data, int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = data[beg + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = data[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = beg;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            i++;
        } else {
            data[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = right[j];
        j++;
        k++;
    }
}
