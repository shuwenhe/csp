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
	var postorder func(*TreeNode)
	postorder = func(node *TreeNode) {
		if node == nil {
			return
		}
		postorder(node.Left)
		postorder(node.Right)
		res = append(res, node.Val)
	}
	postorder(root)
	return
}
