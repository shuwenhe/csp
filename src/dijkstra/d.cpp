#include <iostream>
#include <climits>

using namespace std;

// 定义图中的顶点数量
#define V 6

// 辅助函数：找到距离数组中最小距离的顶点
int minDistance(int dist[], bool sptSet[]) {
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++) {
if (!sptSet[v] && dist[v] <= min) {
min = dist[v];
min_index = v;
}
}

return min_index;
}

// 辅助函数：打印最短路径
void printSolution(int dist[]) {
cout << "顶点 \t 最短距离" << endl;
for (int i = 0; i < V; i++) {
cout << i << " \t " << dist[i] << endl;
}
}

// Dijkstra算法实现
void dijkstra(int graph[V][V], int start) {
int dist[V];
bool sptSet[V];

// 初始化距离数组和sptSet数组
for (int i = 0; i < V; i++) {
dist[i] = INT_MAX;
sptSet[i] = false;
}

dist[start] = 0;

for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet);
sptSet[u] = true;

for (int v = 0; v < V; v++) {
if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}

printSolution(dist);
}

int main() {
int graph[V][V] = {{0, 2, 4, 0, 0, 0},
{2, 0, 3, 7, 0, 0},
{4, 3, 0, 4, 3, 0},
{0, 7, 4, 0, 1, 5},
{0, 0, 3, 1, 0, 2},
{0, 0, 0, 5, 2, 0}};

int start = 0; // 从顶点0开始查找最短路径

cout << "从顶点" << start << "出发的最短路径：" << endl;
dijkstra(graph, start);

return 0;
}
