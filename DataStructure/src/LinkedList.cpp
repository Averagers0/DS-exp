#include "LinkedList.h"
#include <iostream>
using namespace std;

//构造函数
LinkedList::LinkedList() : head(nullptr) {}

//插入新节点
void LinkedList::insert(int val) {
    Node* node = new Node{val, head};
    head = node;
}

//打印链表
void LinkedList::print() {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
