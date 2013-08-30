#ifndef RB_TREE_H
#define RB_TREE_H

#include <cstddef>
#include <functional>
#include <vector>

using namespace std;

/**
 * T: Type of the elements.
 * Compare: Comparison class -- A class such that the expression comp(a, b),
 * where comp is an object of this class and a and b are of type T, returns
 * negative, zero, or positive if a is considered to be smaller than, equal to,
 * or bigger than b respectively. The default is minus<T>.
 *
 * RBTree ensures taht no path is more than twice as long as any other, by
 * forcing every simple path from a node to a leaf contains the same number of
 * black nodes. Therefore the tree is approx. balanced.
 */
template <class T, class Compare = minus<T> >
class RBTree {
private:
    Compare comp;
   
    // Private inner class of tree node.
    class Node {
    public:
        T value;
        bool isRed;     // True indicates red, false indicates black.
                        // NULL 'node' is black node.
                        // If the node is red, then both children are black.
        Node *left;
        Node *right;
        Node *parent;

        Node(T v, bool r) {
            value = v;
            isRed = r;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
    };

    Node *root;

    Node *minimum(Node *node);
    Node *maximum(Node *node);
    Node *predecessor(Node *node);
    Node *successor(Node *node);

    void leftRotate(Node *node);
    void rightRotate(Node *node);

    void insert(Node *node);
    Node *remove(Node *node);
    void removeFixUp(Node *node, Node *parent, bool isLeftChild);
    
    void inorderWalk(Node *curNode) const;
    void sort(vector<T>& array, Node *curNode) const;

public:
    RBTree();
    ~RBTree();
    void insertRB(const T &value);
    bool removeRB(const T &value);
    void inorderWalk() const;
    void sort(vector<T>& array) const;
};

#include "RBTree.cpp"

#endif
