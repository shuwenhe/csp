package rotateRight_leetcode_61

import (
	"fmt"
	"testing"
)

type rotateRight struct {
	para
	ans
}

type para struct {
	one []int
	k   int
}

type ans struct {
	one []int
}

func TestRotateRight(t *testing.T) {
	qs := []rotateRight{
		{
			para{[]int{1, 2, 3, 4, 5}, 2},
			ans{[]int{4, 5, 1, 2, 3}},
		},
	}
	fmt.Printf("LeetCode_61")
	for _, q := range qs {
		_, p := q.ans, q.para
		fmt.Printf("input %v output %v\n", p, structures)
	}

}
