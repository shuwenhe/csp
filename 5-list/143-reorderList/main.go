// https://leetcode-cn.com/problems/reorder-list/
// idea：找到中点断开，翻转后面部分，然后合并前后两个链表
// 1,2,3,4,5,6
// 1,2,3 | 4,5,6
// 1,2,3 | 6,5,4
// 1,6,2,5,3,4

package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l2 := &ListNode{
		Val:  3,
		Next: nil,
	}
	l := &ListNode{
		Val:  2,
		Next: l2,
	}
	head := &ListNode{
		Val:  1,
		Next: l,
	}
	reorderList(head)
	traverse(head)
}

func traverse(p *ListNode) {
	for p != nil {
		fmt.Println(p.Val)
		p = p.Next
	}
}

func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	mid := findMiddle(head)
	tail := reverseList(mid.Next)
	mid.Next = nil
	head = mergeTwoLists(head, tail)
}

// find middle node
func findMiddle(head *ListNode) *ListNode {
	fast := head.Next
	slow := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	return slow
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{Val: 0}
	head := dummy
	toggle := true
	for l1 != nil && l2 != nil {
		// 节点切换
		if toggle {
			head.Next = l1
			l1 = l1.Next
		} else {
			head.Next = l2
			l2 = l2.Next
		}
		toggle = !toggle
		head = head.Next
	}
	// 连接l1未处理完节点
	for l1 != nil {
		head.Next = l1
		head = head.Next
		l1 = l1.Next
	}
	// 连接l2未处理完节点
	for l2 != nil {
		head.Next = l2
		head = head.Next
		l2 = l2.Next
	}
	return dummy.Next
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	for head != nil {
		// 保存当前head.Next节点，防止重新赋值后被覆盖
		// 一轮之后状态：nil<-1 2->3->4
		//              prev head
		temp := head.Next
		head.Next = prev
		// prev 移动
		prev = head
		// head 移动
		head = temp
	}
	return prev
}
