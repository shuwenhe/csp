#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	ofstream fout("sort.out");
	vector<int> nums = {4,2,7,1,5};
	for(int i=0; i < nums.size();i++){
		fout<<nums[i]<<" ";
	}
	sort(nums.begin(),nums.end());
	for(int i = 0; i < nums.size(); i++){
		fout<<nums[i]<<",";
	}
	return 0;
}
