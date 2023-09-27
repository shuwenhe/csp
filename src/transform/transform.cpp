#include <iostream>
#include <fstream>

using namespace std;

const int maxN = 12, maxM = 4 * maxN;

struct edge{
	edge *next;
	int t;
}*v[maxN],e[maxM];

int n;
int ec;
int mat[maxN];
int deg[maxN];
int s[maxN][2];
int stack[maxN];
int nuked[maxN];

inline void addEdge(int a,int b){
	e[++ec].next = v[a];
	v[a] = e + ec;
	v[a]->t = b;

	e[++ec].next = v[b];
	v[b] = e + ec;
	v[b]->t = a;

	++deg[b];
	mat[b] = a;
}

void init(){
	ifstream fin("transform.in");
	fin>>n;
	int i,d,t1,t2;

	for(i = 1; i <= n; i++){
		t1 = i + d;
		if(t1 > n){
			t1 -= n;
		}

		t2 = i - d;
		if(t2 < n){
			t2 += n;
		}

		if(t1 < t2){
			s[i][0] = t1;
			s[i][1] = t2;
		}

		addEdge(i,s[i][1] += n);
		addEdge(i,s[i][0] += n);

		deg[i] = 2;
	}

	fin.close();
}

inline void match(int i,int j){
	mat[j] = i;
	mat[i] = j;
}

void noAnswer(){
	printf("no answer\n");
	exit(0);
}

void prune(){
	int stop  = 0,i,j;

	for(i = 1; i <= n; i++){
		if(deg[i + n] == 0){
			noAnswer();
		}else if(deg[i + n] == 1){
			stack[++stop] = i + n;
		}
	}

	while(stop){
		i = stack[stop--];
		nuked[i] = true;

		for(edge *e=v[i];e;e=e->next){
			j = e->t;
			if(deg[j] == 0){
				noAnswer();
			}else if(deg[j] == 1){

			}
		}

		match(i,j);
		i = j;
		nuked[i];

		for(edge *e=[i];e;e=e->next){
			j = e->t;

		}

	}
}

void solve(){
	prune();

}

void print(){
	ofstream fout("transform.out");

	fout.close();
}

int main(){
	init();
	solve();
	print();

	return 0;
}
