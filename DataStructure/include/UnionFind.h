#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief 节点类，表示并查集中的一个元素
 */
class Node {
public:
    int value;          // 元素值（编号）
    Node* parent;       // 指向父节点（根节点的 parent = nullptr）

    explicit Node(int val);
};

/**
 * @brief 并查集类（Union-Find Disjoint Set）
 */
class UnionFind {
private:
    std::vector<Node*> nodes;  // 保存所有节点

    Node* findRoot(Node* elem); // 查找根节点

public:
    explicit UnionFind(int n);           // 初始化 n 个元素
    void unite(int a, int b);            // 合并 a 和 b 所在的集合
    void processAndOutput();             // 处理并输出结果
};

#endif // UNION_FIND_H
