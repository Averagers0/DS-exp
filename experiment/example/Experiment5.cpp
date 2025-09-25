#include <iostream>
#include <string>
using namespace std;
class zzhStack {
private:
    int* inittable;
    int s_top;
    int capacity;

public:
    zzhStack(int size) {
        inittable = new int[size];
        capacity = size;
        s_top = -1;
    }

    ~zzhStack() {
        delete[] inittable;
    }

    int zzhFull() {
        return s_top == capacity - 1;
    }

    int zzhEmpty() {
        return s_top == -1;
    }

    void s_push(int value0) {
        if (zzhFull()) {
            return;
        }
        inittable[++s_top] = value0;
    }

    int s_pop() {
        if (zzhEmpty()) {
            return -1;
        }
        return inittable[s_top--];
    }

    int getTop() {
        if (zzhEmpty()) {
            return -1;
        }
        return inittable[s_top];
    }
};//stack
bool signJudge(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return true;
    else
        return false;
}//符号判断
string getString(string s) {
    getline(cin, s);
    return s;
}//输入字符串
int Lsign(char a) {
    if (a == '(')
        return 1;
    else
        return 0;
}//左括号判断
int Rsign(char a) {
    if (a == ')')
        return 1;
    else
        return 0;
}//右括号判断
int cal(char sign0,int value1, int value2) {
    switch (sign0) {
    case '+':
        return value1 + value2;
    case '-':
        return value1 - value2;
    case '*':
        return value1 * value2;
    case '/':
        return value1 / value2;
    default:
        return 0;
    }
}//计算
int changeID(char a) {
    return (int)(a - '0');
}//字符转数字
bool priJudge(char a,char b) {
    if ((a!='*' && a!='/')||(b!='+' && b!='-')) {
        return true;
    }
    else {
        return false;
    }
}//优先级判断
int evaMain(string s) {
    zzhStack data_s(s.length());
    zzhStack sign_s(s.length());

    for (int i = 0; i < s.length(); i++) {
        if (Lsign(s[i])) {
            sign_s.s_push(s[i]);
        }
        if (Rsign(s[i])) {
            while (!sign_s.zzhEmpty() && sign_s.getTop() != '(') {
                int data2 = data_s.s_pop();
                int data1 = data_s.s_pop();
                char sign0 = sign_s.s_pop();
                int result = cal(sign0,data1,data2);
                data_s.s_push(result);
            }
            sign_s.s_pop();
        }
        if (isdigit(s[i])) {
            int num0 = 0;
            while (i < s.length() && isdigit(s[i])) {
                num0 = (num0 * 10) + changeID(s[i]);
                i++;
            }
            data_s.s_push(num0);
            i--;
        }
        if (signJudge(s[i])) {
            while ((!sign_s.zzhEmpty()) && sign_s.getTop() != '(' && (priJudge(s[i],sign_s.getTop()))) {
                int data2 = data_s.s_pop();
                int data1 = data_s.s_pop();
                char sign0 = sign_s.s_pop();
                int result = cal(sign0, data1, data2);
                data_s.s_push(result);
            }
            sign_s.s_push(s[i]);
        }
    }
    while (!sign_s.zzhEmpty()) {
        int data2 = data_s.s_pop();
        int data1 = data_s.s_pop();
        char sign0 = sign_s.s_pop();
        int result = cal(sign0, data1, data2);
        data_s.s_push(result);
    }
    return data_s.s_pop();
}
int main() {
    cout << "Input" << endl;
    string zzh;
    getline(cin, zzh);
    int r = evaMain(zzh);
    cout << "Output" << endl;
    cout <<"=" << r << endl;
    cout << "End" << endl;
    system("pause");
    return 0;
}