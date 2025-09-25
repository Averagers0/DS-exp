#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
using namespace std;
class treeNodes {
public:
	treeNodes(char value) {
		this->data = value;
		this->L = nullptr;
		this->R = nullptr;
	}
public:
	char data;
	treeNodes* L;
	treeNodes* R;
};
class erchatree {
public:
	treeNodes* head;
	erchatree() {
		head = nullptr;
	}
	//method:
	void levelcin(string s) {
		int i = 0;
		head =new treeNodes(s[i]);
		queue<treeNodes*>inittable;
		inittable.push(head);
		i++;
		while (!inittable.empty()&&i < s.length()) {
			treeNodes* curr = inittable.front();
			inittable.pop();
			if (i<s.length()) {
				curr->L = new treeNodes(s[i]);
				inittable.push(curr->L);
			}
			i++;
			if (!inittable.empty() && i < s.length()) {
				curr->R = new treeNodes(s[i]);
				inittable.push(curr->R);
			}
			i++;
		}
	}
	void levelcout() {
		if (head == nullptr) {
			return;
		}
		queue<treeNodes*> q;
		q.push(head);
		while (!q.empty()) {
			treeNodes* current = q.front();
			q.pop();
			cout << current->data;
			if (current->L != nullptr) {
				q.push(current->L);
			}
			if (current->R != nullptr) {
				q.push(current->R);
			}
			if (!q.empty()) {
				cout << ",";
			}
		}
		cout << endl;
	}
	void Mcout(treeNodes* one,string& s) {
		if (one != nullptr) {
			s.push_back(one->data);
			Mcout(one->L,s);
			Mcout(one->R,s);
		}
	}
	void Lcout(treeNodes* one,string& s) {
		if (one != nullptr) {
			Lcout(one->L,s);
			s.push_back(one->data);
			Lcout(one->R,s);
		}
	}
	void Rcout(treeNodes* one,string& s) {
		if (one != nullptr) {
			Rcout(one->L,s);
			Rcout(one->R,s);
			s.push_back(one->data);
		}
	}
	void prtcout(string& s) {
		cout << s[0];
		for (int i = 1; i < s.length(); i++) {
			cout << ',' << s[i];
		}
		cout << endl;
	}
	void count(treeNodes* one,int& co) {
		if (one != nullptr) {
			co++;
			count(one->L,co);
			count(one->R,co);
		}
	}
	void buildTree(string preorder, string inorder) {
		head = buildTreeHelper(preorder, inorder, 0, 0, inorder.length() - 1);
	}
private:
	treeNodes* buildTreeHelper(const string& preorder, const string& inorder, int preStart, int inStart, int inEnd) {
		if (preStart > preorder.length() - 1 || inStart > inEnd) {
			return nullptr;
		}

		treeNodes* root = new treeNodes(preorder[preStart]);
		int inIndex = 0;
		for (int i = inStart; i <= inEnd; i++) {
			if (inorder[i] == root->data) {
				inIndex = i;
			}
		}

		root->L = buildTreeHelper(preorder, inorder, preStart + 1, inStart, inIndex - 1);
		root->R = buildTreeHelper(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);

		return root;
	}
};
int main() {
	string zzh;
	string r1;//前序序列输入表
	string r2;//中序序列输入表
	string r3;//后序序列输出表
	erchatree A;//第一个二叉树
	string Lprt;
	string Mprt;
	string Rprt;//前中后输出
	int co=0;//结点
	cout << "Input1" << endl;
	getline(cin, zzh);
	A.levelcin(zzh);//层次遍历输入
	cout << "Output1" << endl;
	A.Mcout(A.head,Mprt);
	A.Lcout(A.head,Lprt);
	A.Rcout(A.head,Rprt);
	A.prtcout(Mprt);
	A.prtcout(Lprt);
	A.prtcout(Rprt);
	A.count(A.head,co);
	cout << co << endl;//结点数目
	cout << ceil(log2(co+1)) << endl;//高度
	cout << "Input2" << endl;
	erchatree B;
	getline(cin, r1);
	getline(cin, r2);
	B.buildTree(r1, r2);
	cout << "Output2" << endl;
	B.Rcout(B.head,r3);
	B.prtcout(r3);
	B.levelcout();//层次遍历输出
	cout << "End" << endl;
	system("pause");
	return 0;
}