#include <bits/stdc++.h>

using namespace std;

const int maxN = 5, big = 1e9;

int n,m,k;
int a,b,w;
int y[maxN];

vector<array<int,2>> adj[maxN];

int d1[maxN];
array<int,2> d2[maxN];

void dijkstra(){
	priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
	memset(d1,0x7f,4*n);
	d1[n - 1] = 0;
	pq.push({0,n - 1});

	while(pq.size()){
		array<int,2> u = pq.top();
		pq.pop();
		if(u[0] > d1[u[1]]){
			continue;
		}

		for(array<int,2> v : adj[u[1]]){
			if(d1[v[1]] > u[0] + v[0]){
				d1[v[1]] = u[0] + v[0];
				pq.push({d1[v[1]],v[1]});
			}
		}
	}
}

void dijkstra2(){
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
	memset(d2,0x7f,sizeof(d2[0])*n);
	d2[n - 1] = {big,n - 1};
	pq.push({big, n - 1,n - 1});
	
	for(int i = 0; i < n - 1; i++){
		if(!y[i]){
			continue;
		}
		d2[i] = {d1[i] + big - y[i], i};
		pq.push({d1[i] + big - y[i],i,i});
	}

	while(pq.size()) {
		array<int, 3> u = pq.top();
		pq.pop();
		if(array<int,2>{u[0],u[1]} > d2[u[2]]){
			continue;
		}

		for(array<int,2> v : adj[u[2]]){
			if(d2[v[1]] > array<int,2>{u[0] + v[0],u[1]}){
				d2[v[1]] = {u[0] + v[0], u[1]};
				pq.push({u[0]+v[0], u[1], v[1]});
			}
		}
	}
}

int main(){
	ifstream fin("dining.in");
	ofstream fout("dining.out");

	fin>>n>>m>>k;
	
	while(m--){
		fin>>a>>b>>w;
		--a,--b;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}

	while(k--){
		fin>>a>>b;
		--a;
		y[a] = max(b,y[a]);
	}

	dijkstra();
	dijkstra2();

	for(int i = 0 ; i < n - 1; i++){
		fout<<(d2[i][1] < n - 1 || y[n - 1])<<"\n";
	}
}
