// https://leetcode.com/problems/binary-tree-preorder-traversal/
// Input: root = [1,null,2,3]
// Output: [1,2,3]

package preorderTraversal

import "fmt"

type TreeNode struct {
	Left, Right *TreeNode
	Val         int
}

func preorderTraversal(root *TreeNode) (vals []int) {
	stack := []*TreeNode{}
	fmt.Println("len(stack) = ", len(stack))
	node := root
	for node != nil || len(stack) > 0 {
		for node != nil {
			vals = append(vals, node.Val)
			stack = append(stack, node)
			node = node.Left
		}
		node = stack[len(stack)-1].Right
		stack = stack[:len(stack)-1]
	}
	return
}
