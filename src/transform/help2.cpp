/* 
 * Problem: NOI2009 transform
 * Author: Shuwen He
 * Memo: 二分图匹配 + 修正
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=20001,MAXM=MAXN*4;

struct edge{
	edge *next;
	int t;
}*V[MAXN],ES[MAXM];

int N,EC,Current;
int S[MAXN][2],mat[MAXN];
bool vis[MAXN];

inline void addedge(int a,int b){
	ES[++EC].next = V[a]; V[a] = ES + EC;
	V[a]->t = b;
}

void init(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&N);
	int i,d,t1,t2;
	for (i=1;i<=N;i++){
		scanf("%d",&d);
		t1 = i + d;
		if (t1>N) t1-=N;
		t2 = i - d;
		if (t2<1) t2+=N;
		if (t1 < t2)
			S[i][0] = t1,S[i][1] = t2;
		else
			S[i][0] = t2,S[i][1] = t1;
		addedge(i,S[i][0]+=N);
		addedge(i,S[i][1]+=N);
	}
}

bool augment(int i){
	if (i <= Current)
		return false;
	for (edge *e=V[i];e;e=e->next){
		int j = e->t;
		if (!vis[j]){
			vis[j] = true;
			if (!mat[j] || augment(mat[j])){
				mat[j] = i;
				mat[i] = j;
				return true;
			}
		}
	}
	return false;
}

void hungary(){
	Current = 0;
	int cnt = 0;
	for (int i=1;i<=N;i++){
		memset(vis,0,sizeof(vis));
		if (augment(i))
			cnt++;
	}
	if (cnt < N){
		printf("No Answer\n");
		exit(0);
	}
}

void fix(){
	for (int i=1;i<=N;i++){
		if (mat[i] != S[i][0]){
			Current = i;
			memset(vis,0,sizeof(vis));
			
			int t = mat[ S[i][0] ];
			
			mat[ S[i][1] ] = 0;
			mat[ S[i][0] ] = i;
			vis[ S[i][0] ] = true;
			
			if (augment(t)){
				mat[i] = S[i][0];
			}else{
				mat[ S[i][1] ] = i;
				mat[ S[i][0] ] = t;
			}
		}
	}
}

void solve(){
	hungary();
	fix();
}

void print(){
	int i;
	for (i=1;i<N;i++)
		printf("%d ",mat[i] - N - 1);
	printf("%d\n",mat[i] - N - 1);
}

int main(){
	init();
	solve();
	print();
	return 0;
}
