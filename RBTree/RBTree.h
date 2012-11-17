#ifndef RB_TREE_H
#define RB_TREE_H

#include <cstddef>
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
        bool isRed;     // True indicates red, false indicates black.
                        // NULL 'node' is black node.
                        // If the node is red, then both children are black.
        Node *left;
        Node *right;
        Node *parent;

        Node(T &v, bool r) {
            value = v;
            isRed = r;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
    };

    Node *root;

    void leftRotate(Node *node);
    void rightRotate(Node *node);

    void insert(Node *node);
    void remove(Node *node);

public:
    RBTree();
    ~RBTree();
    void insertRB(T &value);
    void removeRB(T &value);
};

#include "RBTree.cpp"

#endif
