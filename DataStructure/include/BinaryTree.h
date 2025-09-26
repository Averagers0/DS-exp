#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <string>

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree();

    // 用层序遍历序列构建树
    void buildFromLevelOrder(const std::string& seq);

    // 用前序+中序遍历序列构建树
    void buildFromPreInOrder(const std::string& preorder, const std::string& inorder);

    // 遍历方法
    void preorder(TreeNode* node, std::string& result);
    void inorder(TreeNode* node, std::string& result);
    void postorder(TreeNode* node, std::string& result);
    void levelorder();

    // 工具方法
    void printWithComma(const std::string& s);
    int countNodes(TreeNode* node);
    int getHeight(TreeNode* node);

private:
    TreeNode* buildHelper(const std::string& preorder, const std::string& inorder,
                          int preStart, int inStart, int inEnd);
};

#endif // BINARYTREE_H
