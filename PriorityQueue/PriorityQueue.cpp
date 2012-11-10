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
    int pIndex = parent(i);

    if (comp(queue[i], queue[pIndex])) {
        T temp = queue[i];
        queue[i] = queue[pIndex];
        queue[pIndex] = temp;

        heapifyUp(pIndex);
    }
}

template <class T, class Compare>
PriorityQueue<T, Compare>::PriorityQueue() {
    //TODO: implementation.
}

template <class T, class Compare>
PriorityQueue<T, Compare>::PriorityQueue(vector<T> elements) {
    //TODO: implementation.
}

template <class T, class Compare>
bool PriorityQueue<T, Compare>::isEmpty() const {
    return queue.empty();
}

template <class T, class Compare>
int PriorityQueue<T, Compare>::size() const {
    return queue.size();
}

template <class T, class Compare>
const T& PriorityQueue<T, Compare>::popTop() {
    //TODO: implementation.
    return queue[0];
}

template <class T, class Compare>
void PriorityQueue<T, Compare>::push(const T& element) {
    //TODO: implementation.
}
