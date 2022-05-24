package postorderTraversal

import (
	"fmt"
	"testing"
)

func TestPostorderTraversal(t *testing.T) {
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
	fmt.Println(postorderTraversal(&root))
}
