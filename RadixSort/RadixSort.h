#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "../CountingSort/CountingSort.h"
#include <vector>

using namespace std;

static int divisor;

/**
 * Compare two number on a particular digit by using divisor.
 */
static bool smallerOnDigit(int a, int b) {
    a /= divisor;
    b /= divisor;
    a %= 10;
    b %= 10;
    return a < b ? true : false;
}

/**
 * Radix sort using the stable counting sort as its intermediate sort.
 * This algorithm ensures O(n) running time because the k factor in the counting
 * sort is constant (9). However the constant factor of this running time is a
 * bit high, and it does not sort in place because the counting sort does not do
 * so.
 *
 * Assume all elements in input are non-negative integers.
 */
void radixSort(vector<int>& input, vector<int>& output) {
    output = input;
    vector<int> temp;

    // Get the number of bits.
    int bits = sizeof(int) << 3;

    // Sort starting from the least significant bit.
    divisor = 1;
    for (int i = 0; i < bits; i++) {
        countingSort(output, temp, smallerOnDigit);
        output = temp;
        divisor *= 10;
    }
}

#endif
