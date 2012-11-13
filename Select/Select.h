#ifndef SELECT_H
#define SELECT_H

#include <vector>
#include <algorithm>        // sort()

using namespace std;

template <class T>
static int selectIndex(vector<T>& elements, int start, int end, int i);

template <class T>
static int partition(vector<T>& elements, int start, int end) {
    int num = end - start + 1;
    int reminder = num % 5;
    int groupNum = (num / 5) + (reminder ? 1 : 0);
    if (reminder == 0) {
        reminder = 5;
    }

    // Sort each group, where the group has 5 memebers at most.
    for (int i = 0; i < groupNum; i++) {
        T temp;
        if (i != groupNum - 1) {
            sort(elements.begin() + start + i * 5,
                 elements.begin() + start + i * 5 + 5);
            temp = elements[start + 2 + 5 * i];
            elements[start + 2 + 5 * i] = elements[start + i];
            elements[start + i] = temp;
        } else {
            sort(elements.begin() + start + i * 5,
                 elements.begin() + start + i * 5 + reminder);
            temp = elements[start + (num - 5 * i) / 2];
            elements[start + (num - 5 * i) / 2] = elements[start + i];
            elements[start + i] = temp;
        }
    }

    // Recursive call to get the median of medians.
    int pivot = selectIndex(elements, start, start + groupNum - 1,
                            start + groupNum / 2);
    
    // Acutally do the partition now.
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
static int selectIndex(vector<T>& elements, int start, int end, int i) {
    if (start == end) {
        return i;
    }

    int pivot = partition(elements, start, end);
    
    if (pivot == i) {
        return i;
    } else if (pivot > i) {
        return selectIndex(elements, start, pivot - 1, i);
    } else {
        return selectIndex(elements, pivot + 1, end, i);
    }
}

/**
 * Return the value of the ith ordered element in linear time in worst case by
 * ensuring nice divide when finding the pivot.
 * The value of i starts from 0 (minimum).
 * This function could modify the ordering of the input elements.
 */
template <class T>
T& select(vector<T>& elements, int i) {
    return elements[selectIndex(elements, 0, elements.size() - 1, i)];
}

#endif
