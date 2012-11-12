#include "CountingSort.h"
#include <assert.h>
#include <iostream>

int main() {
    vector<int> elements;
    elements.push_back(543);
    elements.push_back(643);
    elements.push_back(4);
    elements.push_back(20);
    elements.push_back(0);
    elements.push_back(0);
    elements.push_back(20);

    vector<int> output;
    countingSort(elements, output);
  
    assert(output.size() == 7);
    assert(output[0] == 0);
    assert(output[1] == 0);
    assert(output[2] == 4);
    assert(output[3] == 20);
    assert(output[4] == 20);
    assert(output[5] == 543);
    assert(output[6] == 643);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
