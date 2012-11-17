#include <cstddef>

/**
 * Assume the right child of node is not NULL.
 */
template <class T, class Compare>
void RBTree<T, Compare>::leftRotate(Node *node) {
    Node *y = node->right;

    node->right = y->left;
    if (y->left != NULL) {
        y->left->parent = node;
    }

    y->parent = node->parent;

    if (node->parent == NULL) {
        root = y;
    } else {
        if (node == node->parent->left) {
            node->parent->left = y;
        } else {
            node->parent->right = y;
        }
    }

    y->left = node;
    node->parent = y;
}

/**
 * Assume the left child of node is not NULL.
 */
template <class T, class Compare>
void RBTree<T, Compare>::rightRotate(Node *node) {
    Node *x = node->left;

    node->left = x->right;
    if (x->right != NULL) {
        x->right->parent = node;
    }

    x->parent = node->parent;

    if (node->parent == NULL) {
        root = x;
    } else {
        if (node == node->parent->left) {
            node->parent->left = x;
        } else {
            node->parent->right = x;
        }
    }

    x->right = node;
    node->parent = x;
}

template <class T, class Compare>
void RBTree<T, Compare>::insert(Node *node) {
    Node *top = NULL;
    Node *bottom = root;

    while (bottom != NULL) {
        top = bottom;
        if (comp(node->value, bottom->value)) {
            bottom = bottom->left;
        } else {
            bottom = bottom->right;
        }
    }

    node->parent = top;
    if (top == NULL) {
        root = node;
    } else {
        if (comp(node->value, top->value)) {
            top->left = node;
        } else {
            top->right = node;
        }
    }
}

template <class T, class Compare>
void RBTree<T, Compare>::remove(Node *node) {
}

template <class T, class Compare>
void RBTree<T, Compare>::insertRB(T &value) {
    Node *node = new Node(value, true);
    insert(node);
    
    // Correct if the property of RB tree is violated.
    while (node != root && node->parent->isRed) {
        // node is red, and node's parent is also red, this needs fix.
        // Since the root of the tree is always black, we know for sure that
        // the parent of node is not the root, and the parent of parent of node
        // exists.

    }

    // Ensure the root of the tree is always black.
    root->isRed = false;
}

template <class T, class Compare>
void RBTree<T, Compare>::removeRB(T &value) {
}

template <class T, class Compare>
RBTree<T, Compare>::RBTree() {
    root = NULL;
}

template <class T, class Compare>
RBTree<T, Compare>::~RBTree() {
    while (root != NULL) {
        Node *temp = root;
        remove(root);
        delete temp;
    }
}
