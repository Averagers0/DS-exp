#ifndef TREENODE_H
#define TREENODE_H

/**
 * @brief 二叉树结点
 */
class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

#endif // TREENODE_H
