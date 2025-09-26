#include "HeapSort.h"
#include <algorithm>

void heapify(vector<int>& Z, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && Z[left] > Z[largest]) {
        largest = left;
    }
    if (right < size && Z[right] > Z[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(Z[i], Z[largest]);
        heapify(Z, size, largest);
    }
}

void buildHeap(vector<int>& Z) {
    int size = Z.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(Z, size, i);
    }
}

void heapSort(vector<int>& Z) {
    int size = Z.size();
    buildHeap(Z);
    for (int i = size - 1; i > 0; --i) {
        swap(Z[0], Z[i]);
        heapify(Z, i, 0);
    }
}
