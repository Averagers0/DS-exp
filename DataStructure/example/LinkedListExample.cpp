#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list1, list2;
    int num;

    cout << "Input1" << endl;
    cin >> num;
    while (num != 0) {
        list1.insertSorted(num);
        cin >> num;
    }
    cout << "Output1" << endl;
    list1.print();

    cout << "Input2" << endl;
    cin >> num;
    while (num != 0) {
        list2.insertSorted(num);
        cin >> num;
    }
    cout << "Output2" << endl;
    list2.print();

    // 合并 list2 到 list1
    ListNode* curr = list2.head;
    while (curr != nullptr) {
        list1.insertSorted(curr->value);
        curr = curr->next;
    }
    cout << "Combine" << endl;
    list1.print();

    // 插入操作
    int insertNum;
    cout << "Insert" << endl;
    cin >> insertNum;
    list1.insertSorted(insertNum);
    cout << "Insertion" << endl;
    list1.print();

    // 删除操作
    int removeNum;
    cout << "Delete" << endl;
    cin >> removeNum;
    list1.erase(removeNum);
    cout << "Deletion" << endl;
    list1.print();

    // 查找操作
    int searchNum;
    cout << "Find" << endl;
    cin >> searchNum;
    int pos = list1.search(searchNum);
    cout << "Position" << endl << pos << endl;

    cout << "End" << endl;
    system("pause");
    return 0;
}
