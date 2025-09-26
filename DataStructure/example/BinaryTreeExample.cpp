#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // 输入1：层序序列建树
    cout << "Input1" << endl;
    string levelSeq;
    getline(cin, levelSeq);

    BinaryTree treeA;
    treeA.buildFromLevelOrder(levelSeq);

    cout << "Output1" << endl;
    string pre, in, post;
    treeA.preorder(treeA.root, pre);
    treeA.inorder(treeA.root, in);
    treeA.postorder(treeA.root, post);

    treeA.printWithComma(pre);
    treeA.printWithComma(in);
    treeA.printWithComma(post);

    int nodeCount = treeA.countNodes(treeA.root);
    cout << nodeCount << endl;               // 节点数
    cout << treeA.getHeight(treeA.root) << endl; // 树高度

    // 输入2：前序+中序建树
    cout << "Input2" << endl;
    string preorder, inorder;
    getline(cin, preorder);
    getline(cin, inorder);

    BinaryTree treeB;
    treeB.buildFromPreInOrder(preorder, inorder);

    cout << "Output2" << endl;
    string post2;
    treeB.postorder(treeB.root, post2);
    treeB.printWithComma(post2);
    treeB.levelorder();

    cout << "End" << endl;
    return 0;
}
