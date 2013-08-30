#include <iostream>

/**
 * Get the minimum node in the tree rooted at 'node'.
 */
template <class T, class Compare>
typename RBTree<T, Compare>::Node *RBTree<T, Compare>::minimum(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/**
 * Get the maximum node in the tree rooted at 'node'.
 */
template <class T, class Compare>
typename RBTree<T, Compare>::Node *RBTree<T, Compare>::maximum(Node *node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

template <class T, class Compare>
typename RBTree<T, Compare>::Node *RBTree<T, Compare>::predecessor(Node *node) {
    if (node->left != NULL) {
        return maximum(node->left);
    }
    Node *parent = node->parent;
    while (parent != NULL && node == parent->left) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

template <class T, class Compare>
typename RBTree<T, Compare>::Node *RBTree<T, Compare>::successor(Node *node) {
    if (node->right != NULL) {
        return minimum(node->right);
    }
    Node *parent = node->parent;
    while (parent != NULL && node == parent->right) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

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
        if (comp(node->value, bottom->value) < 0) {
            bottom = bottom->left;
        } else {
            bottom = bottom->right;
        }
    }

    node->parent = top;
    if (top == NULL) {
        root = node;
    } else {
        if (comp(node->value, top->value) < 0) {
            top->left = node;
        } else {
            top->right = node;
        }
    }
}

/**
 * Fix the colors and perform necessary rotation to re-balance the tree after
 * a deletion.
 */
template <class T, class Compare>
void RBTree<T, Compare>::removeFixUp(Node *node, Node *parent,
                                     bool isLeftChild) {
    Node *sibling;

    while (node != root && (node == NULL || node->isRed == false)) {
        if (isLeftChild) {
            sibling = parent->right;
            
            // First make sure the sibling is black.
            if (sibling->isRed) {
                // Swap color between parent and sibling.
                sibling->isRed = false;
                parent->isRed = true;
                leftRotate(parent);
                sibling = parent->right;
            }

            // Now the sibling must be black.
            if ((sibling->left == NULL || sibling->left->isRed == false) &&
                (sibling->right == NULL || sibling->right->isRed == false)) {
                sibling->isRed = true;
            }
            else {
                if (sibling->right->isRed == false) {
                    // Make sure the sibling's left child is black, right child is red.
                    sibling->left->isRed = false;
                    sibling->isRed = true;
                    rightRotate(sibling);

                    sibling = parent->right;
                }

                // Now the sibling's left child is black, right child is red.
                sibling->isRed = parent->isRed;
                parent->isRed = false;
                sibling->right->isRed = false;
                leftRotate(parent);

                node = root;
                continue;
            }

        } else {
            sibling = parent->left;
            
            // First make sure the sibling is black.
            if (sibling->isRed) {
                // Swap color between parent and sibling.
                sibling->isRed = false;
                parent->isRed = true;
                rightRotate(parent);
                sibling = parent->left;
            }

            // Now the sibling must be black.
            if ((sibling->left == NULL || sibling->left->isRed == false) &&
                (sibling->right == NULL || sibling->right->isRed == false)) {
                sibling->isRed = true;
            }
            else {
                if (sibling->left->isRed == false) {
                    // Make sure the sibling's right child is black, left child is red.
                    sibling->right->isRed = false;
                    sibling->isRed = true;
                    leftRotate(sibling);

                    sibling = parent->left;
                }

                // Now the sibling's right child is black, left child is red.
                sibling->isRed = parent->isRed;
                parent->isRed = false;
                sibling->left->isRed = false;
                rightRotate(parent);

                node = root;
                continue;
            }
        }

        // Update.
        node = parent;
        parent = parent->parent;
        if (node == parent->left) {
            isLeftChild = true;
        } else {
            isLeftChild = false;
        }
    }

    node->isRed = false;
}

template <class T, class Compare>
typename RBTree<T, Compare>::Node *RBTree<T, Compare>::remove(Node *node) {
    bool isLeftChild = true;
    Node *splicedOutNode;
    if (node->left == NULL || node->right == NULL) {
        splicedOutNode = node;
    } else {
        splicedOutNode = successor(node);
    }

    Node *child;
    if (splicedOutNode->left != NULL) {
        child = splicedOutNode->left;
    } else {
        child = splicedOutNode->right;
    }

    if (child != NULL) {
        child->parent = splicedOutNode->parent;
    }

    if (splicedOutNode->parent == NULL) {
        root = child;
    } else if (splicedOutNode == splicedOutNode->parent->left) {
        splicedOutNode->parent->left = child;
        isLeftChild = true;
    } else {
        splicedOutNode->parent->right = child;
        isLeftChild = false;
    }

    if (splicedOutNode != node) {
        node->value = splicedOutNode->value;
    }

    // Rebalance the tree if needed.
    if (root != NULL && splicedOutNode->isRed == false) {
        removeFixUp(child, splicedOutNode->parent, isLeftChild);
    }

    return splicedOutNode;
}

template <class T, class Compare>
void RBTree<T, Compare>::insertRB(const T &value) {
    Node *node = new Node(value, true);
    insert(node);
    
    // Correct if the property of RB tree is violated.
    while (node != root && node->parent->isRed) {
        // node is red, and node's parent is also red, this needs fix.
        // Since the root of the tree is always black, we know for sure that
        // the parent of node is not the root, and the parent of parent of node
        // exists.
        // So, we also know that the node's parent's parent is black.

        if (node->parent == node->parent->parent->left) {
            Node *uncle = node->parent->parent->right;
            if (uncle->isRed) {
                // Uncle node is also red, just need to swap color.
                node->parent->isRed = false;
                uncle->isRed = false;
                uncle->parent->isRed = true;
                node = uncle->parent;
            } else {
                // Uncle node is black, need rotation.
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rightRotate(node->parent->parent);
            }
        } else {
            Node *uncle = node->parent->parent->left;
            if (uncle->isRed) {
                // Uncle node is also red, just need to swap color.
                node->parent->isRed = false;
                uncle->isRed = false;
                uncle->parent->isRed = true;
                node = uncle->parent;
            } else {
                // Uncle node is black, need rotation.
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                leftRotate(node->parent->parent);
            }
        }
    }

    // Ensure the root of the tree is always black.
    root->isRed = false;
}

/**
 * Return true if value is found in the tree. Otherwise return false.
 */
template <class T, class Compare>
bool RBTree<T, Compare>::removeRB(const T &value) {
    Node *node = root;
    while (node != NULL) {
        if (comp(value, node->value) < 0) {
            node = node->left;
        } else if (comp(value, node->value) > 0) {
            node = node->right;
        } else {
            break;
        }
    }

    if (node == NULL) {
        return false;
    } else {
        Node *node = remove(node);
        delete node;
        return true;
    }
}

template <class T, class Compare>
void RBTree<T, Compare>::inorderWalk(Node *curNode) const {
    if (curNode != NULL) {
        inorderWalk(curNode->left);
        std::cout << curNode->value << std::endl;
        inorderWalk(curNode->right);
    }
}

template <class T, class Compare>
void RBTree<T, Compare>::inorderWalk() const {
    inorderWalk(root);
}

template <class T, class Compare>
void RBTree<T, Compare>::sort(vector<T>& array, Node *curNode) const {
    if (curNode != NULL) {
        sort(array, curNode->left);
        array.push_back(curNode->value);
        sort(array, curNode->right);
    }
}

template <class T, class Compare>
void RBTree<T, Compare>::sort(vector<T>& array) const {
    sort(array, root);
}

template <class T, class Compare>
RBTree<T, Compare>::RBTree() {
    root = NULL;
}

template <class T, class Compare>
RBTree<T, Compare>::~RBTree() {
    while (root != NULL) {
        Node *temp = remove(root);
        delete temp;
    }
}
