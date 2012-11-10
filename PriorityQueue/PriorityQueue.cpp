/**
 * Assume that the binary tree rooted at l_child(i) and r_child(i) are heaps,
 * the ith element might be violating the heap property by having priority less
 * than at least one of its children. This function corrects such situation so
 * that the tree rooted at i becomes a heap.
 */
template <class T, class Compare>
void PriorityQueue<T, Compare>::heapifyDown(int i) {
    int lchildIndex = l_child(i);
    int rchildIndex = r_child(i);
    int hpIndex = i;

    if (lchildIndex < queue.size() &&
            comp(queue[lchildIndex], queue[hpIndex])) {
        hpIndex = lchildIndex;
    }
    if (rchildIndex < queue.size() &&
            comp(queue[rchildIndex], queue[hpIndex])) {
        hpIndex = rchildIndex;
    }

    if (hpIndex != i) {
        T temp = queue[i];
        queue[i] = queue[hpIndex];
        queue[hpIndex] = temp;

        heapifyDown(hpIndex);
    }
}

/**
 * Assume that the entire binary tree is a heap except the ith element, the ith
 * element might be violating the heap property by having priority higher than
 * its parent. This function corrects such situation so that the entire tree
 * becomes a heap.
 */
template <class T, class Compare>
void PriorityQueue<T, Compare>::heapifyUp(int i) {
    int pIndex;
    
    if (i == 1) {
        // At the root.
        return;
    }
    
    pIndex = parent(i);

    if (comp(queue[i], queue[pIndex])) {
        T temp = queue[i];
        queue[i] = queue[pIndex];
        queue[pIndex] = temp;

        heapifyUp(pIndex);
    }
}

template <class T, class Compare>
PriorityQueue<T, Compare>::PriorityQueue() {
    // Root is at index 1, so put a mock object at index 0.
    T mockObj;
    queue.push_back(mockObj);
}

template <class T, class Compare>
PriorityQueue<T, Compare>::PriorityQueue(vector<T> elements) {
    // Root is at index 1, so put a mock object at index 0.
    T mockObj;
    queue.push_back(mockObj);
    
    queue.insert(queue.end(), elements.begin(), elements.end());

    // Now build the priority queue.
    for (int i = queue.size() - 1; i >= 1; i--) {
        heapifyDown(i);
    }
}

template <class T, class Compare>
bool PriorityQueue<T, Compare>::isEmpty() const {
    return queue.size() == 1;
}

template <class T, class Compare>
int PriorityQueue<T, Compare>::size() const {
    return queue.size() - 1;
}

template <class T, class Compare>
const T& PriorityQueue<T, Compare>::top() const {
    return queue[1];
}

template <class T, class Compare>
void PriorityQueue<T, Compare>::pop() {
    queue[1] = queue.back();
    queue.pop_back();
    heapifyDown(1);
}

template <class T, class Compare>
void PriorityQueue<T, Compare>::insert(const T& element) {
    queue.push_back(element);
    heapifyUp(queue.size() - 1);
}

/**
 * Sort the entire tree such that for any subtree:
 * priority(root) >= priority(left child) >= priority(right child).
 */
template <class T, class Compare>
void PriorityQueue<T, Compare>::sortQueue() {
    vector<T> tempQueue;
    T temp;
    tempQueue.push_back(temp);

    while (!queue.isEmpty()) {
        tempQueue.push_back(top());
        pop();
    }

    queue = tempQueue;
}
