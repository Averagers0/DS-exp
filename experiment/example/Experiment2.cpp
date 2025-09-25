#include<iostream>
#include<vector>
using namespace std;
void insertSort(vector<int>& conTable) {
    int n = conTable.size();
    for (int i = 1; i < n; i++) {
        int key = conTable[i];
        int j = i - 1;
        while (j >= 0 && conTable[j] > key) {
            conTable[j + 1] = conTable[j];
            j--;
        }
        conTable[j + 1] = key;
    }
}
void bubbleSort(vector<int>& conTable) {
    int n = conTable.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (conTable[j] > conTable[j + 1]) {
                swap(conTable[j], conTable[j + 1]);
            }
        }
    }
}
void merge(vector<int>& conTable, int low, int mid, int high) {
    int lengthOfLeft = mid - low + 1;
    int lengthOfRight = high - mid;
    vector<int> L(lengthOfLeft);
    vector<int> R(lengthOfRight);
    for (int i = 0; i < lengthOfLeft; i++) {
        L[i] = conTable[low + i];
    }
    for (int j = 0; j < lengthOfRight; j++) {
        R[j] = conTable[mid + 1 + j];
    }
    int index1 = 0, index2 = 0, index0 = low;
    while (index1 < lengthOfLeft && index2 < lengthOfRight) {
        if (L[index1] <= R[index2]) {
            conTable[index0] = L[index1];
            index1++;
        }
        else {
            conTable[index0] = R[index2];
            index2++;
        }
        index0++;
    }
    while (index1 < lengthOfLeft) {
        conTable[index0] = L[index1];
        index1++;
        index0++;
    }
    while (index2 < lengthOfRight) {
        conTable[index0] = R[index2];
        index2++;
        index0++;
    }
}
void mergeSort(vector<int>& conTable, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(conTable, low, mid);
        mergeSort(conTable, mid + 1, high);
        merge(conTable, low, mid, high);
    }
}
int main() {
    vector<int> initDataTable;
    int zzh;
    cout << "Input" << endl;
    cout << "1-Bubble Sort" << "," << "2-Insert Sort" << "," << "3-Select Sort" << endl;
    cin >> zzh;
    int s = initDataTable.size();
    while (zzh!=0) {
        initDataTable.push_back(zzh);
        s = initDataTable.size();
        if (s == 18)
        {
            break;
        }
        cin >> zzh;
        
    }
    int zzh_choice;
    cin >> zzh_choice;
    switch (zzh_choice) {
    case 1:
        cout << "Output" << endl;
        bubbleSort(initDataTable);
        cout << "Bubble Sort"<<endl;
        break;
    case 2:
        cout << "Output" << endl;
        insertSort(initDataTable);
        cout << "Insert Sort"<<endl;
        break;
    case 3:
        cout << "Output" << endl;
        mergeSort(initDataTable,0,initDataTable.size() - 1);
        cout << "Select Sort"<<endl;
        break;
    default:
        break;
    }
    for (int i = 0; i < initDataTable.size(); i++) {
        if (i != initDataTable.size() - 1) {
            cout << initDataTable[i] << ",";
        }
        else {
            cout << initDataTable[i];
        }
    }
    cout << endl<< "End" << endl;
    cout << "Ver1" << endl;
    system("pause");
    return 0;
}