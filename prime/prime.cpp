#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num){
	if(num < 2){
		return false;
	}else if(num == 2){
		return true;
	}

	for(int i = 2;i <= num/i;i++){
		if(num % i == 0){
			return false;
		}
		return true;
	}
	return true;
}

int main(){
	int num = 9;
	cout<<isPrime(num)<<endl;
}
