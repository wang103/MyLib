#include "Select.h"
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
  
    assert(select(elements, 5) == 543);
    assert(select(elements, 3) == 20);
    assert(select(elements, 0) == -34);
    assert(select(elements, 1) == 0);
    assert(select(elements, 6) == 643);
    assert(select(elements, 2) == 4);
    assert(select(elements, 4) == 20);
    
    std::cout << "All tests passed!" << std::endl;

    return 0;
}
