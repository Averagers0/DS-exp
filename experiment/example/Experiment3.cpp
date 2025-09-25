#include <iostream>
using namespace std;
class ListNode {
public:
    int zzh_value;
    ListNode* next;
    ListNode(int val) {
        this->zzh_value = val;
        this->next = nullptr;
    }
};
class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        head = nullptr;
    }
    void insertAndsort(int value) {
        ListNode* node = new ListNode(value);
        if (head == nullptr||value<head->zzh_value) {
            node->next = head;
            head = node;
        }
        else {
            ListNode* curr = head;
            while (curr->next != nullptr && value >= curr->next->zzh_value) {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next = node;
        }
    }
    void zzh_erase(int val) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr && curr->zzh_value != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (prev == nullptr) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
        }
    }
    void zzh_print() {
        if (head == nullptr) {
            cout << "<null>" << endl;
            return;
        }

        ListNode* curr = head;

        while (curr != nullptr) {
            cout << curr->zzh_value;
            if (curr->next != nullptr) {
                cout << ",";
            }
            curr = curr->next;
        }

        cout << endl;
    }
    int zzh_search(int val) {
        int zzh_position = 1;
        ListNode* curr = head;
        while (curr != nullptr && curr->zzh_value != val) {
            curr = curr->next;
            zzh_position++;
        }

        if (curr == nullptr) {
            zzh_position = 0;
        }
        return zzh_position;
    }
};
int main() {
    LinkedList list1;
    LinkedList list2;
    int zzh;
    cout << "Input1" << endl;
    cin >> zzh;
    while (zzh != 0) {
        list1.insertAndsort(zzh);
        cin >> zzh;
    }
    cout << "Output1"<<endl;
    list1.zzh_print();

    cout << "Input2" << endl;
    cin >> zzh;
    while (zzh != 0) {
        list2.insertAndsort(zzh);
        cin >> zzh;
    }
    cout << "Output2"<<endl;
    list2.zzh_print();

    ListNode* curr = list2.head;
    while (curr != nullptr) {
        list1.insertAndsort(curr->zzh_value);
        curr = curr->next;
    }
    cout << "Combine"<<endl;
    list1.zzh_print();
    int insertNum;
    cout << "Insert"<<endl;
    cin >> insertNum;
    list1.insertAndsort(insertNum);
    cout << "Insertion"<<endl;
    list1.zzh_print();
    int removeNum;
    cout << "Delete" << endl;
    cin >> removeNum;
    list1.zzh_erase(removeNum);
    cout << "Deletion"<<endl;
    list1.zzh_print();
    int searchNum;
    cout << "Find"<<endl;
    cin >> searchNum;
    int position = list1.zzh_search(searchNum);
    if (position == 0) {
        cout <<"Position"<<endl<< 0 << endl;
    }
    else {
        cout <<"Position"<< endl<<position<< endl;
    }
    cout << "End" << endl;
    system("pause");
    return 0;
}