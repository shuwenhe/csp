#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 定义图的邻接矩阵表示
const int MAX = numeric_limits<int>::max();
typedef vector<vector<int>> Graph;

// Dijkstra算法实现
vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, MAX);  // 存储起始点到各个顶点的最短距离
    vector<bool> visited(n, false);  // 记录顶点是否已访问
    dist[start] = 0;  // 起始点到自身的距离为0

    // 优先队列按照距离从小到大排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        // 更新与u相邻的顶点的最短距离
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    // 构建图的邻接矩阵表示
    Graph graph = {
        {0, 2, 4, MAX, MAX},
        {2, 0, 1, 4, MAX},
        {4, 1, 0, 2, 7},
        {MAX, 4, 2, 0, 1},
        {MAX, MAX, 7, 1, 0}
    };

    int start = 0;  // 起始点
    vector<int> dist = dijkstra(graph, start);

    // 输出起始点到各个顶点的最短距离
    for (int i = 0; i < dist.size(); ++i) {
        cout << "Distance from " << start << " to " << i << ": " << dist[i] << endl;
    }

    return 0;
}
