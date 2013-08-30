#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

using namespace std;

/**
 * Pick the pivot using the median-of-three method.
 */
template <class T>
static int getPivotIndex(vector<T>& elements, int start, int end) {
    int median = (start + end + 1) / 2;
    
    T a = elements[start];
    T b = elements[median];
    T c = elements[end];

    if (a > b && a > c) {
        return b > c ? median : end;
    }
    if (b > a && b > c) {
        return a > c ? start : end;
    }
    return a > b ? start : median;
}

template <class T>
static int partition(vector<T>& elements, int start, int end) {
    int pivot = getPivotIndex(elements, start, end);
    T pivotElement = elements[pivot];

    T temp = elements[pivot];
    elements[pivot] = elements[end];
    elements[end] = temp;

    int storeIndex = start;
    for (int i = start; i < end; i++) {
        if (elements[i] < pivotElement) {
            temp = elements[storeIndex];
            elements[storeIndex] = elements[i];
            elements[i] = temp;
            storeIndex++;
        }
    }

    temp = elements[end];
    elements[end] = elements[storeIndex];
    elements[storeIndex] = temp;

    return storeIndex;
}

template <class T>
static void quickSort(vector<T>& elements, int start, int end) {
    if (start < end) {
        int pivot = partition(elements, start, end);
        quickSort(elements, start, pivot - 1);
        quickSort(elements, pivot + 1, end);
    }
}

template <class T>
void quickSort(vector<T>& elements) {
    quickSort(elements, 0, elements.size() - 1);
}

#endif
