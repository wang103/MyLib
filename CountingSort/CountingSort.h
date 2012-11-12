#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <vector>

using namespace std;

/**
 * Used to sort non-negative integers. Let k be the largest integer in the
 * input, the running time is O(n) if k is O(n).
 */
void countingSort(vector<int>& input, vector<int>& output) {
    output.clear();

    if (input.size() == 0) {
        return;
    }

    // Find the largest integer in input.
    int k = input[0];
    for (int i = 0; i < (int)input.size(); i++) {
        if (input[i] > k) {
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

    // countings[i] is how many inputs are <= than i.
    // Sorting starts from the last element to maintain stability.
    for (int i = (int)input.size() - 1; i >= 0; i--) {
        output[--countings[input[i]]] = input[i];
    }
}

#endif
