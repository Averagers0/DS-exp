#include "BinarySearchTree.h"

TreeNode::TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

TreeNode* BinarySearchTree::insertNode(TreeNode* curr, int val) {
    if (curr == nullptr) {
        return new TreeNode(val);
    }

    if (val < curr->data) {
        curr->left = insertNode(curr->left, val);
    } else if (val > curr->data) {
        curr->right = insertNode(curr->right, val);
    }
    return curr;
}

void BinarySearchTree::insert(int val) {
    root = insertNode(root, val);
}

void BinarySearchTree::preorder(TreeNode* curr, vector<int>& A) {
    if (curr != nullptr) {
        A.push_back(curr->data);
        preorder(curr->left, A);
        preorder(curr->right, A);
    }
}

void BinarySearchTree::inorder(TreeNode* curr, vector<int>& B) {
    if (curr != nullptr) {
        inorder(curr->left, B);
        B.push_back(curr->data);
        inorder(curr->right, B);
    }
}

void BinarySearchTree::preorderTraversal(vector<int>& A) {
    preorder(root, A);
}

void BinarySearchTree::inorderTraversal(vector<int>& B) {
    inorder(root, B);
}
