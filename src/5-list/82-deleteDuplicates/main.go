// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l6 := &ListNode{
		Val:  7,
		Next: nil,
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
	showNode(lists)
}

// 遍历链表
func showNode(p *ListNode) {
	for p != nil {
		fmt.Println(*p)
		p = p.Next
	}
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	// 链表头结点可能被删除，用dummy node 辅助删除
	// dummy := &ListNode{0, head}
	dummy := &ListNode{Val: 0}
	dummy.Next = head
	head = dummy
	var rmVal int
	for head.Next != nil && head.Next.Next != nil {
		if head.Next.Val == head.Next.Next.Val {
			// 记录已经删除的值，用于后续节点判断
			rmVal = head.Next.Val
			for head.Next != nil && head.Next.Val == rmVal {
				head.Next = head.Next.Next
			}
		} else {
			head = head.Next
		}
	}
	return dummy.Next
}

// a->b->c delete b, a.next = c
// 访问x.next x.value一定要保证x!=nil
