#include <iostream>
#include <fstream>

using namespace std;

long long factorial(int n){
	long long result = 1;
	for(int i = 2; i <= n; i++){
		result *= i;
	}
	return result;
}

int main(){
	ifstream fin("factorial.in");
	ofstream fout("factorial.out");

	int num;
	long long result;
	fin>>num;
	result = factorial(num);

	fout<<result;

	return 0;
}
