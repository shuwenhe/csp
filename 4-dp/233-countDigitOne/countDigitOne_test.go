// https://leetcode.com/problems/number-of-digit-one/submissions/
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// Example 1:
// Input: n = 13
// Output: 6

package countDigitOne

import (
	"fmt"
	"testing"
)

func TestCountDigitOne(t *testing.T) {
	n := 13
	fmt.Println(countDigitOne(n))
}
