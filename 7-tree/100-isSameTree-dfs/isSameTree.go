// https://leetcode.com/problems/same-tree/
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// Input: p = [1,2], q = [1,null,2]
// Output: false
// Input: p = [1,2,1], q = [1,1,2]
// Output: false
package isSameTree

type TreeNode struct {
	Left, Right *TreeNode
	Val         int
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	queue1, queue2 := []*TreeNode{p}, []*TreeNode{q}
	for len(queue1) > 0 && len(queue2) > 0 {
		node1, node2 := queue1[0], queue2[0]
		queue1, queue2 := queue1[1:], queue2[1:]
		if node1.Val != node2.Val {
			return false
		}
		left1, right1 := node1.Left, node1.Right
		left2, right2 := node2.Left, node2.Right
		if condition {

		}

	}
}
