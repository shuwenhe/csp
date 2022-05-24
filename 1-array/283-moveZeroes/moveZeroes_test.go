package main

import (
	"fmt"
	"testing"
)

func TestMoveZeroes(t *testing.T) {
	nums := []int{0, 1, 0, 3, 12}
	fmt.Println("Start:", nums)
	moveZeroes(nums)
	fmt.Println("End:", nums)
}
