#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

using namespace std;

/**
 * Merge two arrays elements[start, middle] and elements[middle + 1, end].
 */
template <class T>
static void merge(vector<T>& elements, int start, int middle, int end) {
    int size1 = middle - start + 1;
    int size2 = end - middle;

    vector<T> part1;
    vector<T> part2;

    int i;
    for (i = start; i <= middle; i++) {
        part1.push_back(elements[i]);
    }
    for (i = middle + 1; i <= end; i++) {
        part2.push_back(elements[i]);
    }

    int index1 = 0;
    int index2 = 0;
    for (i = start; i <= end; i++) {
        T val1 = part1[index1];
        T val2 = part2[index2];

        if (val1 <= val2) {
            elements[i] = val1;
            index1++;
        } else {
            elements[i] = val2;
            index2++;
        }

        if (index1 == size1 || index2 == size2) {
            i++;
            break;
        }
    }

    if (index1 != size1) {
        for (; i <= end; i++, index1++) {
            elements[i] = part1[index1];
        }
    }

    if (index2 != size2) {
        for (; i <= end; i++, index2++) {
            elements[i] = part2[index2];
        }
    }
}

template <class T>
static void mergeSort(vector<T>& elements, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        
        mergeSort(elements, start, middle);
        mergeSort(elements, middle + 1, end);

        merge(elements, start, middle, end);
    }
}

template <class T>
void mergeSort(vector<T>& elements) {
    mergeSort(elements, 0, elements.size() - 1);
}

#endif
