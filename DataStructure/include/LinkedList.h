#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//单链表实现
class LinkedList {
public:
    LinkedList();
    void insert(int val);
    void print();
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
};

#endif
