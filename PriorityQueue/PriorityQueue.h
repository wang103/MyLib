#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

using namespace std;

template <class T>
class PriorityQueue {
private:
    vector<T> queue;

public:
    PriorityQueue();
    bool isEmpty() const;
    int size() const;
    const T& extractMin();
    void push(const T& element);
};

#include "PriorityQueue.cpp"

#endif
