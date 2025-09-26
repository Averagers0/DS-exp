#include "UnionFind.h"

Node::Node(int val) {
    this->value = val;
    this->parent = nullptr;
}

UnionFind::UnionFind(int n) {
    for (int i = 1; i <= n; i++) {
        Node* node = new Node(i);
        nodes.push_back(node);
    }
}

Node* UnionFind::findRoot(Node* elem) {
    if (elem->parent == nullptr) {
        return elem;
    }
    // 路径压缩优化
    elem->parent = findRoot(elem->parent);
    return elem->parent;
}

void UnionFind::unite(int a, int b) {
    Node* rootA = findRoot(nodes[a - 1]);
    Node* rootB = findRoot(nodes[b - 1]);
    if (rootA != rootB) {
        rootB->parent = rootA;
    }
}

void UnionFind::processAndOutput() {
    int n = nodes.size();
    std::vector<std::vector<int>> grouped(n);

    // 按根节点分组
    for (int i = 0; i < n; i++) {
        int rootValue = findRoot(nodes[i])->value - 1;
        grouped[rootValue].push_back(nodes[i]->value);
    }

    // 过滤空集合 + 排序
    std::vector<std::vector<int>> results;
    for (auto& group : grouped) {
        if (!group.empty()) {
            std::sort(group.begin(), group.end());
            results.push_back(group);
        }
    }

    // 输出结果
    std::cout << "Output" << std::endl;
    for (auto& group : results) {
        std::cout << "(";
        for (size_t i = 0; i < group.size(); i++) {
            std::cout << group[i];
            if (i != group.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << ")" << std::endl;
    }
    std::cout << "End" << std::endl;
}
