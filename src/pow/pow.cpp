#include <iostream>
#include <fstream>

using namespace std;

int pow(){
	ifstream fin("pow.in");
	ofstream fout("pow.out");

	int a,b;
	fin>>a>>b;
	long long result = 1;
	for(int i = 0; i < b; i++){
		result *= a;
		if (result > 1000000000){
			fout<<-1<<endl;
			return 0;
		}
	}
	fout<<result<<endl;

	fin.close();
	fout.close();
	return 0;
}

int main(){
	pow();
	return 0;
}
