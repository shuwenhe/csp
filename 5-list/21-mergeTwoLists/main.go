// https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
// 思路：通过 dummy node 链表，连接各个元素
package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	List1 := &ListNode{
		Val:  1,
		Next: nil,
	}
	List2 := &ListNode{}
	fmt.Println(mergeTwoLists(List1, List2))
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{Val: 0}
	head := dummy
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			head.Next = l1
			l1 = l1.Next
		} else {
			head.Next = l2
			l2 = l2.Next
		}
		head = head.Next
	}
	// 连接l1未处理完节点
	for l1 != nil {
		head.Next = l1
		head = head.Next
		l1 = l1.Next
	}
	// 连接l2未处理完成节点
	for l2 != nil {
		head.Next = l2
		head = head.Next
		l2 = l2.Next
	}
	return dummy.Next
}
