package main

import "testing"

// Problem URL: https://leetcode.com/problems/matrix-diagonal-sum/
// Problem ID: 1572
// Status: Accepted
func TestDiagonalSum(t *testing.T) {
	// Row and colums size are the same
	inputNumbers := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	// 1 + 5 + 9 + 3 + 7
	outputValue := diagonalSum(inputNumbers)
	if outputValue != 25 {
		t.Errorf("Expected Value 25")
	}

	// Test with different row and colums size
	testCase2Input := [][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
	}

	// 1 + 6 + 4 + 7
	outputValue = diagonalSum(testCase2Input)
	if outputValue != 18 {
		t.Errorf("Expected value to be 18")
	}
}
