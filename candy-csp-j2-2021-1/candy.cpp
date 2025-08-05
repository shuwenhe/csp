#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream fin("candy.in");
	ofstream fout("candy.out");
	int n,l,r; // 7,16,23 或 10，14，18
	int k; // 6或8
	fin>>n>>l>>r;
	int s = r/n;
	cout<<"s="<<s<<endl;
	if(l<n*(r/n)&&n*(r/n)<r){
		k = n * (r/n) -1-n*(r/n-1);
	}else if(n*(r/n)<l){
		k = r - n;
	}
	fout<<k;
	return 0;
}
