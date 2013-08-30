#include "PriorityQueue.h"
#include <assert.h>
#include <iostream>

int main() {
    vector<int> elements;
    elements.push_back(543);
    elements.push_back(643);
    elements.push_back(4);
    elements.push_back(20);
    elements.push_back(0);
    elements.push_back(-34);
    elements.push_back(20);

    PriorityQueue<int> pq(elements);
  
    assert(pq.size() == 7);

    assert(pq.top() == -34);
    pq.pop();
    assert(pq.top() == 0);
    pq.pop();

    assert(pq.size() == 5);

    pq.insert(0);
    pq.insert(25);

    pq.sortQueue();
    vector<int> actual;
    pq.getVector(actual);

    assert(pq.top() == 0);
    assert(actual[0] == 0);
    pq.pop();
    assert(pq.top() == 4);
    assert(actual[1] == 4);
    pq.pop();
    assert(pq.top() == 20);
    assert(actual[2] == 20);
    pq.pop();
    assert(pq.top() == 20);
    assert(actual[3] == 20);
    pq.pop();
    assert(pq.top() == 25);
    assert(actual[4] == 25);
    pq.pop();
    assert(pq.top() == 543);
    assert(actual[5] == 543);
    pq.pop();
    assert(pq.top() == 643);
    assert(actual[6] == 643);
    pq.pop();
    assert(pq.isEmpty());
    assert(actual.size() == 7);

    PriorityQueue<int, greater<int> > pq2;
    
    assert(pq2.isEmpty());

    pq2.insert(5);
    pq2.insert(1);
    pq2.insert(3);
    pq2.insert(4);

    assert(pq2.size() == 4);

    assert(pq2.top() == 5);
    pq2.pop();
    assert(pq2.top() == 4);
    pq2.pop();
    assert(pq2.top() == 3);
    pq2.pop();
    assert(pq2.top() == 1);
    pq2.pop();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
