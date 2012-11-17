#ifndef RB_TREE_H
#define RB_TREE_H

#include <functional>

using namespace std;

/**
 * T: Type of the elements.
 * Compare: Comparison class -- A class such that the expression comp(a, b),
 * where comp is an object of this class and a and b are of type T, returns true
 * if a is considered to be smaller than b. The default is less<T>.
 *
 * RBTree ensures taht no path is more than twice as long as any other, by
 * forcing every simple path from a node to a leaf contains the same number of
 * black nodes. Therefore the tree is approx. balanced.
 */
template <class T, class Compare = less<T> >
class RBTree {
private:
    Compare comp;
    
    // Private inner class of tree node.
    class Node {
        T &value;
        bool color;     // True indicates red, false indicates black.
                        // NULL also indicates black.
                        // If the node is red, then both children are black.
        Node *left;
        Node *right;
        Node *parent;
    };

public:
    RBTree();
};

#include "RBTree.cpp"

#endif
