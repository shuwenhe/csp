/*
* Problem: NOI2009 DAY1 transform
* Author: Shuwen He
* Memo: 二分图匹配 + 暴力判断
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN=20003,MAXM=MAXN*2;

struct edge{
	edge *next;
	int t;
}*V[MAXN],ES[MAXM];

FILE *fi,*fo;
int N,EC;
int mat[MAXN],S[MAXN][2],T[MAXN];
bool vis[MAXN],lock[MAXN];

inline void addedge(int a,int b){
	ES[++EC].next = V[a];
	V[a] = ES+EC;
	V[a]->t = b;
}

void init(){
	int i,t1,t2,d;
	fi = fopen("transform.in","r");
	fo = fopen("transform.out","w");
	fscanf(fi,"%d",&N);
	EC = 0;
	for (i=1;i<=N;i++){
		fscanf(fi,"%d",&d);
		t1 = i + d;
		if (t1>N) t1-=N;
		t2 = i - d;
		if (t2<1) t2+=N;
		if (t1 < t2)
			S[i][0] = t1,S[i][1] = t2;
		else
			S[i][0] = t2,S[i][1] = t1;
		addedge(i,S[i][1]+N);
		addedge(i,S[i][0]+N);
	}
}

bool aug(int i){
	for (edge *e=V[i];e;e=e->next){
		int j = e->t;
		if (!vis[j] && !lock[j]){
			vis[j] = true;
			if (!mat[j] || aug(mat[j])){
				mat[j] = i;
				return true;
			}
		}
	}
	return false;
}

bool hungary(){
	memset(mat,0,sizeof(mat));
	for (int i=1;i<=N;i++){
		if (lock[i]) continue;
		memset(vis,0,sizeof(vis));
		if (!aug(i))
			return false;
	}
	return true;
}

bool solve(){
	int i,j;
	if (!hungary())
		return false;
	for (i=1;i<=N;i++){
		lock[i] = true;
		for (j=0;j<=1;j++){
			if (!lock[S[i][j]+N]){
				lock[S[i][j]+N] = true;
				if (hungary()){
					T[i] = S[i][j];
					break;
				}
				lock[S[i][j]+N] = false;
			}
		}
	}
	return true;
}

void print(bool win){
	if (win){
		int i;
		for (i=1;i<N;i++)
			fprintf(fo,"%d ",T[i] - 1);
		fprintf(fo,"%d\n",T[i] - 1);
	}
	else
		fprintf(fo,"No Answer\n");
	fclose(fi);
	fclose(fo);
}

int main(){
	init();
	print(solve());
	return 0;
}
