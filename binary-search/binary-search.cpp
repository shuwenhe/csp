#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // mid = (left+right)/2 ?
        
        if (nums[mid] == target) {
            return mid; // 找到目标值，返回索引
        } else if (nums[mid] < target) {
            left = mid + 1; // 目标值在右半部分，更新左边界
        } else {
            right = mid - 1; // 目标值在左半部分，更新右边界
        }
    }
    
    return -1; // 没有找到目标值，返回-1
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
    
    int target = 7;
    int result = binarySearch(nums, target);
    
    if (result != -1) {
        cout << "目标值 " << target << " 在数组中的索引为 " << result << endl;
    } else {
        cout << "目标值 " << target << " 不存在于数组中" << endl;
    }
    
    return 0;
}
