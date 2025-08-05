// https://leetcode-cn.com/problems/reverse-linked-list/
// 反转一个单链表
// 思路：用一个prev节点保存向前指针,temp保存向后的临时指针
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
	lists := reverseList(l)
	showNode(lists) // 遍历链表
	reverseList(l)
}

// 遍历链表
func showNode(p *ListNode) {
	for p != nil {
		fmt.Println(*p)
		p = p.Next
	}

}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	for head != nil {
		// 保证当前head.Next节点，防止重新赋值后被颠覆
		// 一轮后状态：nil->1 2->3->4
		// prev head
		temp := head.Next
		head.Next = prev
		// prev 移动
		prev = head
		// head 移动
		head = temp
	}
	return prev
}
