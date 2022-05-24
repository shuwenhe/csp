// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// 给定一个二叉树，返回它的 中序 遍历
// 思路：通过stack 保存已经访问的元素，用于原路返回

package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	root := TreeNode{Val: 1}
	root.Right = &TreeNode{2, nil, nil}
	root.Right.Left = CreateNode(3)
	fmt.Println(inorderTraversal(&root))
}

func CreateNode(v int) *TreeNode {
	return &TreeNode{Val: v}
}

func inorderTraversal(root *TreeNode) []int {
	result := make([]int, 0)
	if root == nil {
		return result
	}
	stack := make([]*TreeNode, 0)
	for len(stack) > 0 || root != nil {
		for root != nil {
			stack = append(stack, root)
			root = root.Left // 一直向左
		}
		// 弹出
		val := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, val.Val)
		root = val.Right
	}
	return result
}
