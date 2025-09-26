#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
using namespace std;

void heapify(vector<int>& Z, int size, int i);
void buildHeap(vector<int>& Z);
void heapSort(vector<int>& Z);

#endif
