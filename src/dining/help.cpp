#include <bits/stdc++.h>

using namespace std;

const int maxN=5, big=1e9;

int n,m,k;
int a,b,w;
int y[maxN];

int d1[maxN]; // 存储从源节点到图中所有其他节点的最短距离
array<int,2> d2[maxN];

vector<array<int, 2>> adj[maxN];

void dijkstra() { // 从源节点到所有其他节点的最短路径。不考虑饲料影响的最短路径 考虑饲料影响的最短路径
	priority_queue<array<int, 2>,vector<array<int, 2>>,greater<array<int, 2>>> pq; // 存储节点和距离的数组，按照距离的升序进行排序。
	// 初始时，优先队列 pq 中只包含一个元素，即源节点自身，其距离为 0。随着算法的进行，最短路径会逐步从源节点扩展到其他节点。
	memset(d1, 0x7f, 4*n); // 将数组d1的所有元素初始化为0x7f 127
	d1[n-1]=0; // 将源节点到自身的最短距离初始化为0，并将其加入优先队列pq中
	pq.push({0, n-1});

	while(pq.size()) { // 优先队列中会有一个元素，即源节点自身，距离为0，随着算法的进行，最短路径会逐步从源节点扩展到其他节点。
		array<int,2> u = pq.top(); // u[0] 表示节点的距离，u[1] 表示节点的编号。
		pq.pop();
		if(u[0]>d1[u[1]]){ // 如果“u[0]”更大，则意味着已经找到了到节点“u[1]”的更短路径
			continue;
		}

		for(array<int, 2> v : adj[u[1]]) { // 遍历节点u[1]的邻接节点v
			if(d1[v[1]]>u[0]+v[0]) { // 判断是否存在更短的路径从源节点到邻接节点v
				d1[v[1]]=u[0]+v[0]; // 如果存在更短的路径，就更新d1[v[1]]为u[0]+v[0]，表示找到了一条更短的路径。
				pq.push({d1[v[1]], v[1]}); // 将更新后的距离值和节点编号v[1]组成一个array<int, 2>类型的数组，放入优先队列pq中
			}
		}
	}
}

void dijkstra2() { 
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

	memset(d2, 0x7f, sizeof(d2[0])*n); // 将d2数组初始化为一个较大的值（0x7f）
	d2[n-1]={big, n-1};
	pq.push({big, n-1, n-1}); // 将一个元素{big, n-1, n-1}插入到优先队列pq中

	for(int i=0; i<n-1; ++i) {
		if(!y[i]){
			continue;
		}
		d2[i]={d1[i]+big-y[i], i};
		pq.push({d1[i]+big-y[i], i, i});
	}

	while(pq.size()) {
		array<int, 3> u=pq.top();
		pq.pop();
		if(array<int, 2>{u[0], u[1]} > d2[u[2]]){
			continue;
		}

		for(array<int, 2> v : adj[u[2]]) {
			if(d2[v[1]]>array<int, 2>{u[0]+v[0], u[1]}) {
				d2[v[1]]={u[0]+v[0], u[1]};
				pq.push({u[0]+v[0], u[1], v[1]});
			}
		}
	}
}

int main() {
	ifstream fin("dining.in");
	ofstream fout("dining.out");
	
	fin>>n>>m>>k;

	while(m--){
		fin>>a>>b>>w;
		--a,--b;
		adj[a].push_back({w,b});
		adj[b].push_back({w,a});
	}

	while(k--){
		fin>>a>>b;
	       	--a;
		y[a]=max(b,y[a]); // 更新节点 a 的属性或权重，将其更新为 b 和当前节点 a 的属性或权重中的较大值
	}

	dijkstra();
	dijkstra2();

	for(int i = 0; i < n-1; i++){
		fout<<(d2[i][1] < n - 1 || y[n-1]) << '\n';
	}
}
