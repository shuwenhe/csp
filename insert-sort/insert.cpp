#include <iostream>

using namespace std;

int main(){
	for(int i = 1; i <= n; i++){
		for(int j = i; j >= 2; j--){
			if(a[j] < a[j - 1]){
				int t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}

		}

	}
}
