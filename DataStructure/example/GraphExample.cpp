#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    int numVertices, numEdges;
    char dh, comma;

    cout << "Input" << endl;
    cin >> numVertices >> dh >> numEdges;
    Graph graph(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int start, end, weight;
        cin >> start >> comma >> end >> comma >> weight;
        graph.addEdge(start, end, weight);
    }

    cout << "Output" << endl;
    graph.BFS(1);
    graph.DFSoper();

    int shortest = graph.shortestPath(1, numVertices);
    cout << shortest << endl;

    cout << "End" << endl;
    system("pause");
    return 0;
}
