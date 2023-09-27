#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ifstream fin("point.in");
	ofstream fout("point.out");

	int n,k;
	fin>>n>>k;
	int ans = 0;

	vector<pair<int,int>> points(n);
	for(int i = 0; i < n; i++){
		int x,y;
		fin>>x>>y;
		points[i] = {x,y};
	}

	sort(points.begin(),points.end());

	vector<vector<int>> dp(n,vector<int>(k + 1,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = j + 1;
			for(int t = 0; t < i; t++){
				pair<int,int> &A = points[i];
				pair<int,int> &B = points[t];
				int d = A.first - B.first + A.second - B.second - 1;
				if(A.second >= B.second){
					if(j >= d){
						dp[i][j] = max(dp[i][j],dp[t][j - d] + d + 1);
					}
				}
			}
			ans = max(ans,dp[i][j]);
		}
	}

	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
