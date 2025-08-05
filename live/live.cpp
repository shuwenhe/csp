#include <iostream>
#include <fstream>

using namespace std;

int n,w,x;
int a[610];

int main(){
	ifstream fin("live.in");
	ofstream fout("live.out");
	fin>>n>>w;
	int k;
	int ans;
	fout<<n<<' '<<w<<'\n';

	for(int i = 1; i <= n; i++){
		fin>>x;
		a[x]++;
		k = max(1,int(i * w / 100.0));
		ans = 0;
		for(int j = 600; j >= 0; j--){
			if(ans + a[j] < k){
				ans += a[j];
			}else{
				fout<<j<<' ';
				break;
			}
		}
	}

	fout<<'\n';

	fin.close();
	fout.close();

	return 0;
}
