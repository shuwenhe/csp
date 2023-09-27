#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");

	string s;
	fin>>s;
	int count = 0;

	for(int i = 0; i < s.length();i++){
		if(s[i] == '1'){
			count++;
		}
	}
	fout<<count;

	fin.close();
	fout.close();
	return 0;
}

