package maxSubArray

import (
	"fmt"
	"testing"
)

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6

func TestMaxSubArray(t *testing.T) {
	arr := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	fmt.Println(maxSubArray(arr))
}
