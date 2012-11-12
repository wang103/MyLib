#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <vector>

using namespace std;

static bool smaller(int a, int b) {
    return a < b ? true : false;
}

/**
 * A stable counting sort algorithm.
 *
 * Used to sort non-negative integers. Let k be the largest integer in the
 * input, the running time is O(n) if k is O(n).
 * comp is a function point such that camp(a, b) returns true if a should be
 * sorted in front of b.
 */
void countingSort(vector<int>& input, vector<int>& output,
                  bool (*comp)(int, int) = smaller) {
    output.clear();

    if (input.size() == 0) {
        return;
    }

    // Find the largest element in input.
    int k = input[0];
    for (int i = 1; i < (int)input.size(); i++) {
        if (comp(k, input[i])) {
            k = input[i];
        }
    }
    k++;

    output.resize(input.size());
    vector<int> countings(k);

    // Initialize the countings.
    for (int i = 0; i < (int)countings.size(); i++) {
        countings[i] = 0;
    }
    for (int i = 0; i < (int)input.size(); i++) {
        countings[input[i]]++;
    }
    for (int i = 1; i < (int)countings.size(); i++) {
        countings[i] += countings[i - 1];
    }

    // countings[i] is how many elements are <= than i.
    // Sorting starts from the last element to maintain stability.
    for (int i = (int)input.size() - 1; i >= 0; i--) {
        output[--countings[input[i]]] = input[i];
    }
}

#endif
