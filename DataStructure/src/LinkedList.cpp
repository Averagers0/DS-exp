#include "LinkedList.h"
#include <iostream>
using namespace std;

ListNode::ListNode(int val) {
    value = val;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedList::insertSorted(int val) {
    ListNode* node = new ListNode(val);
    if (head == nullptr || val < head->value) {
        node->next = head;
        head = node;
    } else {
        ListNode* curr = head;
        while (curr->next != nullptr && val >= curr->next->value) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
    }
}

void LinkedList::erase(int val) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != nullptr) {
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }
}

void LinkedList::print() const {
    if (head == nullptr) {
        cout << "<null>" << endl;
        return;
    }
    ListNode* curr = head;
    cout << curr->value;
    curr = curr->next;
    while (curr != nullptr) {
        cout << "," << curr->value;
        curr = curr->next;
    }
    cout << endl;
}

int LinkedList::search(int val) const {
    int position = 1;
    ListNode* curr = head;
    while (curr != nullptr && curr->value != val) {
        curr = curr->next;
        position++;
    }
    if (curr == nullptr) return 0;
    return position;
}
