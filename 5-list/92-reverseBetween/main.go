// https://leetcode-cn.com/problems/reverse-linked-list-ii/
// 反转从位置m到n的链表,请使用一趟扫描完成反转
// 输入：1->2->3->4->5
// 输出：1->4->3->2->5
// 思路:先遍历到m处,翻转,再拼接后续,注意指针处理

package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l5 := &ListNode{
		Val:  5,
		Next: nil,
	}
	l4 := &ListNode{
		Val:  4,
		Next: l5,
	}
	l3 := &ListNode{
		Val:  3,
		Next: l4,
	}
	l2 := &ListNode{
		Val:  2,
		Next: l3,
	}
	l := &ListNode{
		Val:  1,
		Next: l2,
	}
	reverseBetween(l, 2, 4)
	traversNode(l)
}

// Traversing the linked list
func traversNode(p *ListNode) {
	for p != nil {
		fmt.Println(*p)
		p = p.Next
	}
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	// 思路：先遍历到m处，翻转，再拼接后续，注意指针处理
	// 输入：1->2->3->4->5->NULL, m=2, n=4
	if head == nil {
		return head
	}
	// 头部变化所以使用dummy node
	dummy := &ListNode{Val: 0}
	dummy.Next = head
	head = dummy
	// 最开始：0->1->2->3->4->5->nil
	var pre *ListNode
	var i = 0
	for i < m {
		pre = head
		head = head.Next
		i++
	}
	// After traversal:1(pre)->2(head)->3->4->5->NULL
	var j = i
	var next *ListNode
	var mid = head
	for head != nil && j <= n {
		temp := head.Next
		head.Next = next
		next = head
		head = temp
		j++
	}

	pre.Next = next
	mid.Next = head
	return dummy.Next
}
