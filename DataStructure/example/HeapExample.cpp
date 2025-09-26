#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
#include "HeapSort.h"
using namespace std;

void veccout(vector<int>& A) {
    if (A.empty()) return;
    cout << A[0];
    for (int i = 1; i < A.size(); i++) {
        cout << "," << A[i];
    }
    cout << endl;
}

int main() {
    int zzh;
    vector<int> input;
    vector<int> preorderResult;
    vector<int> inorderResult;
    vector<int> heapInit;
    vector<int> heapSorted;

    cout << "Input" << endl;
    while (true) {
        cin >> zzh;
        if (zzh == 0) {
            break;
        }
        input.push_back(zzh);
    }

    heapInit = input;
    heapSorted = input;

    cout << "Output" << endl;
    // 大根堆
    buildHeap(heapInit);
    veccout(heapInit);

    // 堆排序
    heapSort(heapSorted);
    veccout(heapSorted);

    // 二叉搜索树
    BinarySearchTree bst;
    for (int val : input) {
        bst.insert(val);
    }
    bst.preorderTraversal(preorderResult);
    veccout(preorderResult);
    bst.inorderTraversal(inorderResult);
    veccout(inorderResult);

    cout << "End" << endl;
    system("pause");
    return 0;
}
