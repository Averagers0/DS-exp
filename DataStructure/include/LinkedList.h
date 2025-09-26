#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val);
};

class LinkedList {
public:
    ListNode* head;

    LinkedList();
    ~LinkedList();

    void insertSorted(int value); // 有序插入
    void erase(int value);        // 删除指定值
    void print() const;           // 打印链表
    int search(int value) const;  // 查找值位置
};

#endif
