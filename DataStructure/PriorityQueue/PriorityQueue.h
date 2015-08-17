#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <functional>

using namespace std;

// Macro for indexing.
#define parent(i) (i >> 1)
#define l_child(i) (i << 1)
#define r_child(i) (i << 1 | 1)

/**
 * T: Type of the elements.
 * Compare: Comparison class -- A class such that the expression comp(a, b),
 * where comp is an object of this class and a and b are of type T, returns true
 * if a is said to have higher priority than b. The default is less<T>.
 */
template <class T, class Compare = less<T> >
class PriorityQueue {
public:
    PriorityQueue();
    PriorityQueue(const vector<T>& elements);
    bool isEmpty() const;
    int size() const;
    const T& top() const;
    void pop();
    void insert(const T& element);
    void sortQueue();
    void getVector(vector<T>& elements) const;

private:
    vector<T> queue;
    Compare comp;

    void heapifyDown(int i);
    void heapifyUp(int i);
};

#include "PriorityQueue.cpp"

#endif
