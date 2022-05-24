// https://leetcode.com/problems/maximum-subarray/
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
package main

func maxSubArray(nums []int) int {
	max := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i-1] > 0 { // 前面元素大于0
			nums[i] += nums[i-1]
		}
		if nums[i] > max {
			max = nums[i]
		}
	}
	return max
}

// Dynamic programming
// Dynamic programming transfer equation
// f(i)代表第i个元素结尾的[连续数组的最大和sum]
// f(i) = max{f(i-1)+nums[i],nums[i]}
// 复杂度
// 时间复杂度：O(n),其中n是nums数组的长度，我们只需要遍历一次数组
// 空间复杂度：O(1),只需要常数空间存放若干变量
