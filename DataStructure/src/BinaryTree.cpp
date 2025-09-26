#include "BinaryTree.h"
#include <queue>
#include <iostream>
#include <cmath>

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::buildFromLevelOrder(const std::string& seq) {
    if (seq.empty()) return;

    int i = 0;
    root = new TreeNode(seq[i++]);
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty() && i < seq.length()) {
        TreeNode* curr = q.front();
        q.pop();

        // 左子树
        if (i < seq.length()) {
            curr->left = new TreeNode(seq[i++]);
            q.push(curr->left);
        }

        // 右子树
        if (i < seq.length()) {
            curr->right = new TreeNode(seq[i++]);
            q.push(curr->right);
        }
    }
}

void BinaryTree::preorder(TreeNode* node, std::string& result) {
    if (node) {
        result.push_back(node->data);
        preorder(node->left, result);
        preorder(node->right, result);
    }
}

void BinaryTree::inorder(TreeNode* node, std::string& result) {
    if (node) {
        inorder(node->left, result);
        result.push_back(node->data);
        inorder(node->right, result);
    }
}

void BinaryTree::postorder(TreeNode* node, std::string& result) {
    if (node) {
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->data);
    }
}

void BinaryTree::levelorder() {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        std::cout << curr->data;
        if (!q.empty()) std::cout << ",";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    std::cout << std::endl;
}

void BinaryTree::printWithComma(const std::string& s) {
    if (s.empty()) return;
    std::cout << s[0];
    for (size_t i = 1; i < s.length(); i++) {
        std::cout << "," << s[i];
    }
    std::cout << std::endl;
}

int BinaryTree::countNodes(TreeNode* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BinaryTree::getHeight(TreeNode* node) {
    if (!node) return 0;
    int leftH = getHeight(node->left);
    int rightH = getHeight(node->right);
    return 1 + std::max(leftH, rightH);
}

void BinaryTree::buildFromPreInOrder(const std::string& preorder, const std::string& inorder) {
    root = buildHelper(preorder, inorder, 0, 0, inorder.length() - 1);
}

TreeNode* BinaryTree::buildHelper(const std::string& preorder, const std::string& inorder,
                                  int preStart, int inStart, int inEnd) {
    if (preStart >= (int)preorder.length() || inStart > inEnd) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[preStart]);

    int inIndex = inStart;
    while (inIndex <= inEnd && inorder[inIndex] != node->data) {
        inIndex++;
    }

    int leftSize = inIndex - inStart;
    node->left = buildHelper(preorder, inorder, preStart + 1, inStart, inIndex - 1);
    node->right = buildHelper(preorder, inorder, preStart + leftSize + 1, inIndex + 1, inEnd);

    return node;
}
