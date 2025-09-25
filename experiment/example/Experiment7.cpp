#include <iostream>
#include <vector>
using namespace std;
class treeNodes {
public:
    int data;
    treeNodes* left;
    treeNodes* right;
    treeNodes(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class erchatree {
private:
    treeNodes* root;
public:
    erchatree() {
        root = NULL;
    }
    void insert(int val) {
        root = insertNode(root, val);
    }
    treeNodes* insertNode(treeNodes* curr, int val) {
        if (curr == NULL) {
            return new treeNodes(val);
        }

        if (val < curr->data) {
            curr->left = insertNode(curr->left, val);
        } else if (val > curr->data) {
            curr->right = insertNode(curr->right, val);
        }

        return curr;
    }
    void preorderTraversal(vector<int>&A) {
        preorder(root,A);
    }
    void preorder(treeNodes* curr,vector<int>&A) {
        if (curr != NULL) {
            A.push_back(curr->data);
            preorder(curr->left,A);
            preorder(curr->right,A);
        }
    }
    void inorderTraversal(vector<int>&B) {
        inorder(root,B);
    }
    void inorder(treeNodes* curr,vector<int>&B) {
        if (curr != NULL) {
            inorder(curr->left,B);
            B.push_back(curr->data);
            inorder(curr->right,B);
        }
    }
};
void heapify(vector<int>& Z, int size, int i) {
    int largest = i; // 标记当前节点及其子节点中最大值的索引
    int left = 2 * i + 1; // 左子节点索引
    int right = 2 * i + 2; // 右子节点索引

    // 如果左子节点大于根节点，则更新 largest
    if (left < size && Z[left] > Z[largest]) {
        largest = left;
    }

    // 如果右子节点大于根节点，则更新 largest
    if (right < size && Z[right] > Z[largest]) {
        largest = right;
    }

    // 如果最大值的位置不是根节点，则交换位置并递归向下调整
    if (largest != i) {
        swap(Z[i], Z[largest]);
        heapify(Z, size, largest);
    }
}

// 初始化大根堆
void buildHeap(vector<int>& Z) {
    int size = Z.size();
    // 从最后一个非叶子节点开始，依次向上调整节点的位置
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(Z, size, i);
    }
}

// 堆排序
void heapSort(vector<int>& Z) {
    int size = Z.size();

    // 构建初始大根堆
    buildHeap(Z);

    // 从堆中依次取出最大值并放置在末尾
    for (int i = size - 1; i > 0; --i) {
        swap(Z[0], Z[i]); // 将堆顶元素与末尾元素交换
        heapify(Z, i, 0); // 缩小堆的规模，重新调整为大根堆
    }
}
void veccout(vector<int>&A) {
    cout << A[0];
    for (int i = 1; i < A.size(); i++) {
        cout << "," << A[i];
    }
    cout << endl;
}
int main() {
    int input[20];
    int count = 0;
    int zzh;
    vector<int>A;
    vector<int>B;
    vector<int>C;
    vector<int>D;
    cout << "Input" << endl;
    while (true) {
        cin >> zzh;
        if (zzh == 0) {
            break;
        }
        input[count++] = zzh;
    }
    for (int i = 0; i < count; i++) {
        C.push_back(input[i]);
        D.push_back(input[i]);
    }
    cout << "Output" << endl;
    buildHeap(C);
    veccout(C);

    heapSort(D);
    veccout(D);
    erchatree bst;
    for (int i = 0; i < count; i++) {
        bst.insert(input[i]);
    }
    bst.preorderTraversal(A);
    veccout(A);
    bst.inorderTraversal(B);
    veccout(B);
    cout << "End" << endl;
    system("pause");
    return 0;
}