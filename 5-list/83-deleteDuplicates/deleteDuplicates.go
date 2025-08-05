// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l7 := &ListNode{
		Val:  8,
		Next: nil,
	}
	l6 := &ListNode{
		Val:  7,
		Next: l7,
	}
	l5 := &ListNode{
		Val:  6,
		Next: l6,
	}
	l4 := &ListNode{
		Val:  3,
		Next: l5,
	}
	l3 := &ListNode{
		Val:  3,
		Next: l4,
	}
	l2 := &ListNode{
		Val:  3,
		Next: l3,
	}
	l := &ListNode{
		Val:  1,
		Next: l2,
	}
	lists := deleteDuplicates(l)
	showNode(lists) // 遍历链表
}

// 遍历链表
func ShowNode(p *ListNode) {
	for p != nil {
		fmt.Println(*p)
		p = p.Next
	}
}

func deleteDuplicates(head *ListNode) *ListNode {
	current := head
	for current != nil {
		// 全部删除完再移动到下一个元素
		for current.Next != nil && current.Val == current.Next.Val {
			current.Next = current.Next.Next
		}
		current = current.Next
	}
	return head
}
