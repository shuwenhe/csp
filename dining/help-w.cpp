#include <bits/stdc++.h>
using namespace std;

#define a array

const int maxN=5, BIG=1e9;
int n, m, k, y[maxN], ai, bi, ti, d1[maxN];
a<int, 2> d2[maxN];
vector<a<int, 2>> adj[maxN];

void dijkstra1() {
	priority_queue<a<int, 2>, vector<a<int, 2>>, greater<a<int, 2>>> pq;
	memset(d1, 0x7f, 4*n);
	d1[n-1]=0;
	pq.push({0, n-1});
	while(pq.size()) {
		a<int, 2> u=pq.top();
		pq.pop();
		if(u[0]>d1[u[1]])
			continue;
		for(a<int, 2> v : adj[u[1]]) {
			if(d1[v[1]]>u[0]+v[0]) {
				d1[v[1]]=u[0]+v[0];
				pq.push({d1[v[1]], v[1]});
			}
		}
	}
}

void dijkstra2() { 
	priority_queue<a<int, 3>, vector<a<int, 3>>, greater<a<int, 3>>> pq;
	memset(d2, 0x7f, sizeof(d2[0])*n);
	d2[n-1]={BIG, n-1};
	pq.push({BIG, n-1, n-1});
	for(int i=0; i<n-1; ++i) {
		if(!y[i])
			continue;
		d2[i]={d1[i]+BIG-y[i], i};
		pq.push({d1[i]+BIG-y[i], i, i});
	}
	while(pq.size()) {
		a<int, 3> u=pq.top();
		pq.pop();
		if(a<int, 2>{u[0], u[1]}>d2[u[2]])
			continue;
		for(a<int, 2> v : adj[u[2]]) {
			if(d2[v[1]]>a<int, 2>{u[0]+v[0], u[1]}) {
				d2[v[1]]={u[0]+v[0], u[1]};
				pq.push({u[0]+v[0], u[1], v[1]});
			}
		}
	}
}

int main() {
	ifstream fin("dining.in");
	ofstream fout("dining.out");
	
	fin >> n >> m >> k;
	while(m--) {
		fin >> ai >> bi >> ti, --ai, --bi;
		adj[ai].push_back({ti, bi});
		adj[bi].push_back({ti, ai});
	}
	while(k--) {
		fin >> ai >> bi, --ai;
		y[ai]=max(bi, y[ai]);
	}
	dijkstra1();
	dijkstra2();

	for(int i=0; i<n-1; ++i)
		fout << (d2[i][1]<n-1||y[n-1]) << "\n";
}
