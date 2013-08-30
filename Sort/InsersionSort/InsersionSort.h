#ifndef INSERSION_SORT_H
#define INSERSION_SORT_H

#include <vector>

using namespace std;

template <class T>
void insersionSort(vector<T>& elements) {
    unsigned int i;
    for (i = 2; i < elements.size(); i++) {
        T curValue = elements[i];

        int lookingIndex;
        for (lookingIndex = i - 1; lookingIndex >= 0; lookingIndex--) {
            if (curValue >= elements[lookingIndex]) {
                break;
            }

            elements[lookingIndex + 1] = elements[lookingIndex];
        }

        elements[lookingIndex + 1] = curValue;
    }
}

#endif
