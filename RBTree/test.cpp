#include "RBTree.h"
#include <assert.h>
#include <iostream>

int main() {
    RBTree<int> rbTree;

    rbTree.insertRB(1);
    rbTree.insertRB(0);
    rbTree.insertRB(2);

    rbTree.inorderWalk();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
