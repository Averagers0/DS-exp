#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class ReGroup {
public:
    int value;
    ReGroup* connection;
    ReGroup(int val) {
        this->connection = nullptr;
        this->value = val;
    }
};
class OEC {
public:
    vector<ReGroup*> v;
public:
    OEC(int n) {
        int c = 0;
        while (c < n) {
            ReGroup* l = new ReGroup(c + 1);
            v.push_back(l);
            c++;
        }
    }
    ReGroup* find(ReGroup* elem) {
        if (elem->connection == nullptr) {
            return elem;
        }
        else {
            return find(elem->connection);
        }
    }
    void OECmerge(int a, int b) {
        ReGroup* Na = find(v[a-1]);
        ReGroup* Nb = find(v[b-1]);
        if (Na != Nb) {
            Nb->connection = Na;
        }
    }
    void dataprocessing() {
        int n = v.size();
        vector<vector<int>> firstData;
        firstData.resize(n);
        for (int i = 0; i < n; i++) {
            int re = find(v[i])->value - 1;
            firstData[re].push_back(v[i]->value);
        }
        vector<vector<int>> LastData;
        for (auto& zzh : firstData) {
            if (!zzh.empty()) {
                sort(zzh.begin(), zzh.end());
                LastData.push_back(zzh);
            }
        }
        OECoutput(LastData);
    }
    void OECoutput(vector<vector<int>>&table) {
        for (auto& zzh : table) {
            cout << "(";
            for (int i = 0; i < zzh.size(); i++) {
                cout << zzh[i];
                if (i != zzh.size() - 1) {
                    cout << ",";
                }
            }
            cout <<")"<< endl;
        }
    }
};
int main() {
    int zzh_N, zzh_R;
    cout << "Input"<<endl;
    cin >> zzh_N;
    OEC initData(zzh_N);
    if (zzh_N < 1 || zzh_N > 9) {
        return 0;
    }
    cin >> zzh_R;
    if (zzh_R <= 0) {
        return 0;
    }
    for (int i = 0; i < zzh_R; i++) {
        int a, b;
        char c;
        cin >> c >> a >> c >> b >> c;
        initData.OECmerge(a, b);
    }
    cout << "Output" << endl;
    initData.dataprocessing();
    cout << "End" << endl;
    cout << "Ver1" << endl;
    system("pause");
    return 0;
}