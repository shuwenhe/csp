#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream fout("bit.out");
	for(int i = 30;i >= 0;i--){
		int power = 1<<i;
		fout<<"power = "<<power<<endl;
	}
	return 0;
}
