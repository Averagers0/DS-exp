#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void coreMethods(vector<int>& init_table, vector<int>& oper_table, vector<int>& judgment_table) {
    if (oper_table.size() == init_table.size()) 
    {
        for (int i = 0; i < oper_table.size(); i++) 
        {
            cout << oper_table[i];
            if (i != oper_table.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < init_table.size(); i++) 
    {
        if (judgment_table[i]) 
        {
            oper_table.push_back(init_table[i]);
            judgment_table[i] = 0;
            coreMethods(init_table, oper_table, judgment_table);
            oper_table.pop_back();
            judgment_table[i] = 1;
        }
    }
}

int main() {
    cout << "Input"<<endl;
    int zzh;
    vector<int> initInputTable;//创造一个初始表用于存放初始数据
    cin >> zzh;
    while (zzh != 0) 
    {
        initInputTable.push_back(zzh);
        cin >> zzh;
    }
    cout << "Output" << endl;
    vector<int> controlsTable;
    vector<int> judgmentTable(initInputTable.size(), 1);//创造一个判别表，用于判断该数据在迭代时是否占用
    sort(initInputTable.begin(), initInputTable.end());//为了美观，将初始列表排序
    coreMethods(initInputTable, controlsTable, judgmentTable);//调用核心方法
    cout << "End" << endl;
    cout << "Ver3" << endl;
    system("pause");
    return 0;
}
