#include <bits/stdc++.h>

using namespace std;

const int v = 6;

void dijkstra(vector<vector<int>> &graph, int startVertex){
	vector<int> distance();

}

int main(){
	vector<vector<int>> graph = {
		{0, 2, 0, 0, 1, 4},
		{2, 0, 3, 0, 0, 0},
        	{0, 3, 0, 6, 0, 0},
	        {0, 0, 6, 0, 0, 5},
        	{1, 0, 0, 0, 0, 2},
	        {4, 0, 0, 5, 2, 0}
	};

	int startVertex = 0;

	dijkstra(graph,startVertex);
}
