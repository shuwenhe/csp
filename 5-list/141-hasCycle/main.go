// https://leetcode-cn.com/problems/linked-list-cycle/
// Given a linked list, determine whether there is a ring in the linked list
// 给定一个链表，判断链表中是否有环
// Idea: Fast and slow pointers, the same fast and slow pointers will have a loop. Prove that if there is a loop, the distance of the speed pointer will decrease by 1 for each step.
// 思路：快慢指针，快慢指针相同则有环，证明：如果有环每走一步快慢指针距离会减1
package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {

}

func hasCycle(head *ListNode) bool {
	// Idea: Fast and slow pointers. If the fast and slow pointers are the same, there is a loop. Prove that if there is a loop, the distance of the speed pointer will decrease by 1 for each step.
	// 思路：快慢指针 快慢指针相同则有环，证明：如果有环每走一步快慢指针距离会减1
	if head == nil {
		return false
	}
	fast := head.Next
	slow := head
	for fast != nil && fast.Next != nil {
		// Compare whether the pointers are equal (don't use Val comparison!)
		// 比较指针是否相等(不要使用Val比较！)
		if fast == slow {
			return true
		}
		fast = fast.Next.Next
		slow = slow.Next
	}
	return false
}
