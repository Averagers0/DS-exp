#include "Graph.h"
#include <climits>  // for INT_MAX

Graph::Graph(int value) {
    numVertices = value;
    adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
}

void Graph::addEdge(int start, int end, int weight) {
    adjMatrix[start - 1][end - 1] = weight;
    adjMatrix[end - 1][start - 1] = weight; // 无向图
}

void Graph::BFS(int start) {
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[start - 1] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current;

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[current - 1][i] && !visited[i]) {
                visited[i] = true;
                q.push(i + 1);
            }
        }

        if (!q.empty()) {
            cout << ",";
        }
    }
    cout << endl;
}

void Graph::DFSUtil(int start, vector<bool>& visited) {
    visited[start - 1] = true;
    cout << start;

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[start - 1][i] && !visited[i]) {
            cout << ",";
            DFSUtil(i + 1, visited);
        }
    }
}

void Graph::DFSoper() {
    vector<bool> visited(numVertices, false);
    DFSUtil(1, visited);
    cout << endl;
}

int Graph::shortestPath(int start, int end) {
    vector<int> dist(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);

    dist[start - 1] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        int minDist = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) {
            return 0; // 不存在路径
        }

        visited[minIndex] = true;

        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[minIndex][j] && !visited[j] &&
                dist[minIndex] != INT_MAX &&
                dist[minIndex] + adjMatrix[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + adjMatrix[minIndex][j];
            }
        }
    }

    return (dist[end - 1] == INT_MAX) ? 0 : dist[end - 1];
}
