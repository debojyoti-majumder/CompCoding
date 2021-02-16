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

// Problem URL: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
func TestIsRoatedAndSorted(t *testing.T) {
	numbers1 := []int{1, 2, 3, 4, 5}
	numbers2 := []int{3, 4, 5, 1, 2}
	numbers3 := []int{2, 1, 3, 4}
	numbers4 := []int{1, 1, 1}

	// This seems to be the failing case
	numbers5 := []int{9, 6, 6, 7}

	if !checkIncRotaed(numbers1) {
		t.Errorf("The array is fine")
	}

	if !checkIncRotaed(numbers2) {
		t.Errorf("Both the arrays are fine")
	}

	if checkIncRotaed(numbers3) && checkIncRotaed(numbers4) {
		t.Errorf("Negavitve test case are not handled correctly")
	}

	if !checkIncRotaed(numbers5) {
		t.Errorf("Number rotation at the last does not seems to be working")
	}
}
