// https://leetcode.com/problems/maximum-subarray/
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
package maxSubArray

func maxSubArray(nums []int) int {
	max := nums[0]                   // 用f数组来保存f(i)的值
	for i := 1; i < len(nums); i++ { // 用一个循环求出所有f(i)
		if nums[i-1] > 0 { // 前面元素大于0
			nums[i] += nums[i-1] // 将前面元素+到当前元素
		}
		if nums[i] > max {
			max = nums[i]
		}
	}
	return max
}

// 动态规划转移方程
// Dynamic programming transfer equation
// f(i) 代表以第i个数结尾的「连续子数组的最大和」
// f(i)=max{f(i−1)+nums[i],nums[i]}
// 复杂度
// 时间复杂度：O(n)，其中n为nums数组的长度。我们只需要遍历一遍数组即可求得答案
// 空间复杂度：O(1)，我们只需要常数空间存放若干变量
