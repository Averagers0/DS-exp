#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val);
};

class BinarySearchTree {
private:
    TreeNode* root;
    TreeNode* insertNode(TreeNode* curr, int val);
    void preorder(TreeNode* curr, vector<int>& A);
    void inorder(TreeNode* curr, vector<int>& B);

public:
    BinarySearchTree();
    void insert(int val);
    void preorderTraversal(vector<int>& A);
    void inorderTraversal(vector<int>& B);
};

#endif
