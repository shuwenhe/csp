package isSameTree

import (
	"fmt"
	"testing"
)

func test(t *testing.T) {
	p1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	p2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   3,
	}
	p := TreeNode{
		Left:  &p1,
		Right: &p2,
		Val:   1,
	}
	q1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	q2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   3,
	}
	q := TreeNode{
		Left:  &q1,
		Right: &q2,
		Val:   1,
	}
	fmt.Println(isSameTree(&p, &q))
}

// Input: p = [1,2], q = [1,null,2]
func test2(t *testing.T) {
	p1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	p := TreeNode{
		Left:  &p1,
		Right: nil,
		Val:   1,
	}

	q2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	q := TreeNode{
		Left:  nil,
		Right: &q2,
		Val:   1,
	}
	fmt.Println(isSameTree(&p, &q))
}

// Input: p = [1,2,1], q = [1,1,2]
func Test3(t *testing.T) {
	p1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	p2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   1,
	}
	p := TreeNode{
		Left:  &p1,
		Right: &p2,
		Val:   1,
	}

	q1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   1,
	}
	q2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	q := TreeNode{
		Left:  &q1,
		Right: &q2,
		Val:   1,
	}
	fmt.Println(isSameTree(&p, &q))
}
