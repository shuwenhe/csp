#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// 定义图的邻接矩阵表示法
const int V = 6; // 图的顶点数

void dijkstra(vector<vector<int>>& graph, int start) {
    vector<int> distance(V, INF);
    vector<bool> visited(V, false);

    distance[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        int minDistance = INF;
        int minIndex = -1;

        // 选择未访问的节点中距离最短的节点
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) {
            break; // 所有节点都已访问
        }

        visited[minIndex] = true;

        // 更新最短路径
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && graph[minIndex][j] != 0 && distance[minIndex] != INF &&
                distance[minIndex] + graph[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + graph[minIndex][j];
            }
        }
    }

    // 打印最短路径
    cout << "顶点\t最短距离\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 0, 1, 4},
        {2, 0, 3, 0, 0, 0},
        {0, 3, 0, 6, 0, 0},
        {0, 0, 6, 0, 0, 5},
        {1, 0, 0, 0, 0, 2},
        {4, 0, 0, 5, 2, 0}
    };

    int startNode = 0; // 起始节点

    dijkstra(graph, startNode);

    return 0;
}
