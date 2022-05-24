// https://leetcode.com/problems/binary-tree-preorder-traversal/
// Input: root = [1,null,2,3]
// Output: [1,2,3]

package preorderTraversal

import (
	"fmt"
	"testing"
)

func TestPreorderTraversal(t *testing.T) {
	l1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   3,
	}
	r1 := TreeNode{
		Left:  &l1,
		Right: nil,
		Val:   2,
	}
	root := TreeNode{
		Left:  nil,
		Right: &r1,
		Val:   1,
	}
	fmt.Println(preorderTraversal(&root))
}
