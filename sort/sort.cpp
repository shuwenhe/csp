#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct node{
	int id;
	int num;
};

int n,q;
node a[8081];

bool cmp(node a, nod b){

}

int main(){
	ifstream fin("sort.in");
	ofstream fout("sort.out");

	fin>>n>>q;
	for(int i = 1; i <= n; i++){
		fin>>a[i].num;
		a[i].id = i;
	}

	sort(a+1,a+1+n,cmp);
	
	return 0;
}
