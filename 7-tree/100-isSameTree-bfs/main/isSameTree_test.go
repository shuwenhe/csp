// https://leetcode.com/problems/same-tree/
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Input: p = [1,2,3], q = [1,2,3]
// Output: true
package main

import (
	"fmt"
	"testing"
)

func TestIsSameTree(t *testing.T) {
	// Input: p = [1,2,3]
	p2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   3,
	}
	p1 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   2,
	}
	p := TreeNode{
		Left:  &p1,
		Right: &p2,
		Val:   1,
	}
	// q = [1,2,3]
	q2 := TreeNode{
		Left:  nil,
		Right: nil,
		Val:   3,
	}
	q1 := TreeNode{
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
