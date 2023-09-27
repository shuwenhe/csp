#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream fin("power.in");
	ofstream fout("power.out");

	long n;
	fin>>n;

	vector<int> partition;
	for(int i = 30;i > 0; i--){
		long power = 1 << i;
		if(n > power){
			partition.push_back(power);
		}
	}

	for(int i = 0; i < partition.size();i++){
		if(partition[i] != 0){
			fout<<partition[i]<<" ";
		}
	}

	fin.close();
	fout.close();

	return 0;
}
