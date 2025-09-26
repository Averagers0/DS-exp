#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Graph {
private:
    int numVertices;                     // 节点数
    vector<vector<int>> adjMatrix;       // 邻接矩阵

    void DFSUtil(int start, vector<bool>& visited);

public:
    Graph(int value);

    void addEdge(int start, int end, int weight); // 添加边
    void BFS(int start);                          // 广度优先遍历
    void DFSoper();                               // 深度优先遍历（从1开始）
    int shortestPath(int start, int end);         // Dijkstra 最短路径
};

#endif
