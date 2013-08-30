#include "InsersionSort.h"
#include <assert.h>
#include <iostream>

int main() {
    vector<int> elements;
    elements.push_back(543);
    elements.push_back(643);
    elements.push_back(4);
    elements.push_back(20);
    elements.push_back(0);
    elements.push_back(-34);
    elements.push_back(20);

    insersionSort(elements);
  
    assert(elements.size() == 7);
    assert(elements[0] == -34);
    assert(elements[1] == 0);
    assert(elements[2] == 4);
    assert(elements[3] == 20);
    assert(elements[4] == 20);
    assert(elements[5] == 543);
    assert(elements[6] == 643);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
