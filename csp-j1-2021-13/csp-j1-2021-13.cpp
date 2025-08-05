#include <iostream>

using namespace std;

int solve(int n){
	if(n <= 1){
		return 1;
	}else if(n >= 5){
		return n * solve(n-2); // solve(7)=7*solve(5)=210 solve(5) = 5*sovle(3)=30 sovle(3) = 3*solve(2)=6 sovle(2) = 2*solve(1)=2 solve(1)=1
	}else{
		return n*solve(n-1);
	}
	return 0;
}

int main(){
	int i = 7;
	int result = solve(7);
	cout<<result<<endl;
	return 0;
}
