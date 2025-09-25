#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// 图的类定义
class Graph {
private:
    int zzh_numVertices; // 节点数
    vector<vector<int>> zzh_Matrix; // 邻接矩阵存储结构
public:
    Graph(int value) {
        zzh_numVertices = value;
        zzh_Matrix.resize(zzh_numVertices, vector<int>(zzh_numVertices, 0));
    }
    // 添加边
    void addEdge(int start, int end, int weight) {
        zzh_Matrix[start - 1][end - 1] = weight;
        zzh_Matrix[end - 1][start - 1] = weight;
    }
    // BFS
    void BFS(int start) {
        vector<bool> visited(zzh_numVertices, false);
        queue<int> q;

        visited[start - 1] = true;
        q.push(start);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current;
            // 获取邻接节点
            for (int i = 0; i < zzh_numVertices; i++) {
                if (zzh_Matrix[current - 1][i] && !visited[i]) {
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

    // DFS遍历
    void DFS(int start, vector<bool>& visited) {
        visited[start - 1] = true;
        cout << start;

        for (int i = 0; i < zzh_numVertices; i++) {
            if (zzh_Matrix[start - 1][i] && !visited[i]) {
                cout << ",";
                DFS(i + 1, visited);
            }
        }
    }

    void DFSoper() {
        vector<bool> visited(zzh_numVertices, false);
        DFS(1, visited);
        cout << endl;
    }

    // 最短路径算法（Dijkstra算法）
    int zzh_shortestPath(int start, int end) {
        vector<int> map0(zzh_numVertices, INT_MAX);
        vector<bool> visited(zzh_numVertices, false);

        map0[start - 1] = 0;

        for (int i = 0; i < zzh_numVertices - 1; i++) {
            int minDist = INT_MAX;
            int minIndex = -1;

            // 寻找当前最短路径的节点
            for (int j = 0; j < zzh_numVertices; j++) {
                if (!visited[j] && map0[j] < minDist) {
                    minDist = map0[j];
                    minIndex = j;
                }
            }

            if (minIndex == -1) {
                // 不存在最短路径，返回特殊值
                return 0;
            }

            visited[minIndex] = true;

            // 更新最短路径
            for (int j = 0; j < zzh_numVertices; j++) {
                if (zzh_Matrix[minIndex][j] && !visited[j] && map0[minIndex] != INT_MAX
                    && map0[minIndex] + zzh_Matrix[minIndex][j] < map0[j]) {
                    map0[j] = map0[minIndex] + zzh_Matrix[minIndex][j];
                }
            }
        }

        if (map0[end - 1] == INT_MAX) {
            // 不存在最短路径，返回特殊值
            return 0;
        }

        return map0[end - 1];
    }
};

int main() {
    int numVertices, numEdges;
    char douhao;
    char dh;
    cout << "Input" << endl;
    cin >>numVertices>>dh>>numEdges;
    Graph graph(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int start, end, weight;
        cin >> start >>douhao>> end >>douhao>> weight;
        graph.addEdge(start, end, weight);
    }
    cout << "Output" << endl;
    graph.BFS(1);
    graph.DFSoper();
    int zzh_SPL = graph.zzh_shortestPath(1, numVertices);
    cout << zzh_SPL << endl;
    cout << "End" << endl;
    system("pause");
    return 0;
}