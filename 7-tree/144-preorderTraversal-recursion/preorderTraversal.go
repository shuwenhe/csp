// https://leetcode.com/problems/binary-tree-preorder-traversal/
// Input: root = [1,null,2,3]
// Output: [1,2,3]

package preorderTraversal

type TreeNode struct {
	Left, Right *TreeNode
	Val         int
}

func preorderTraversal(root *TreeNode) (vals []int) {
	var preorder func(*TreeNode)
	preorder = func(node *TreeNode) {
		if node == nil { // Recursive termination condition
			return
		}
		vals = append(vals, node.Val)
		preorder(node.Left)
		preorder(node.Right)
	}
	preorder(root)
	return
}
