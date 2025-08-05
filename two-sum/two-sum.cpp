#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums,int target){
	unordered_map<int,int> numIndexMap;
	for(int i = 0;i < nums.size();i++){
		int complement = target - nums[i];
		if(numIndexMap.find(complement) != numIndexMap.end()){
			return {numIndexMap[complement],i};
		}
		numIndexMap[nums[i]] = i;
	}
	return {};
}

int main(){
	vector<int> nums = {2,7,11,15};
	int target = 9;
	vector<int> result = twoSum(nums,target);
	if(!result.empty()){
		cout<<result[0]<<" "<<result[1]<<endl;
	}

	return 0;
}
