// https://leetcode.com/problems/number-of-digit-one/submissions/
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// Example 1:
// Input: n = 13
// Output: 6

package countDigitOne

func countDigitOne(n int) (ans int) {
	for k, mulk := 0, 1; n >= mulk; k++ { // mulk = 10^k
		ans += (n/(mulk*10))*mulk + min(max(n%(mulk*10)-mulk+1, 0), mulk)
		mulk *= 10
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
