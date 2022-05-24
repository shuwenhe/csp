// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Input: root = [1,null,2,3]
// Output: [3,2,1]

package postorderTraversal

type TreeNode struct {
	Left, Right *TreeNode
	Val         int
}

func postorderTraversal(root *TreeNode) (res []int) {
	stack := []*TreeNode{}
	var prev *TreeNode
	for root != nil || len(stack) > 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		root = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if root.Right == nil || root.Right == prev {
			res = append(res, root.Val)
			prev = root
			root = nil
		} else {
			stack = append(stack, root)
			root = root.Right
		}
	}
	return
}
