#include "RBTree.h"
#include <assert.h>
#include <iostream>

int main() {
    RBTree<int> rbTree;

    rbTree.insertRB(1);
    rbTree.insertRB(0);
    rbTree.insertRB(2);

    vector<int> array;
    rbTree.sort(array);

    assert(array[0] == 0);
    assert(array[1] == 1);
    assert(array[2] == 2);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
