package main

type MinStack struct {
	min   []int
	stack []int
}

func main() {
	minStack()
}

func Constructor() MinStack {
	return MinStack{
		min:   make([]int, 0),
		stack: make([]int, 0),
	}
}

func minStack() {

}
