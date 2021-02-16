package main

type cellIndex struct {
	x, y int
}

func isVisitedCel(visistedCells []cellIndex, newCell cellIndex) bool {
	if len(visistedCells) == 0 {
		return false
	}

	for _, val := range visistedCells {
		if val.x == newCell.x && val.y == newCell.y {
			return true
		}
	}

	return false
}

func diagonalSum(mat [][]int) int {
	listVisistedCells := []cellIndex{}
	diagSum := 0
	numberOfRows := len(mat)
	if numberOfRows == 0 {
		return 0
	}

	numberOfColumns := len(mat[0])

	for i := 0; i < numberOfRows; i++ {
		if i == numberOfColumns {
			break
		}

		// This is the cell we are looking at
		nCell := cellIndex{x: i, y: i}
		otherCell := cellIndex{x: i, y: numberOfColumns - i - 1}

		if isVisitedCel(listVisistedCells, nCell) == false {
			listVisistedCells = append(listVisistedCells, nCell)
			diagSum += mat[nCell.x][nCell.y]
		}

		if isVisitedCel(listVisistedCells, otherCell) == false {
			listVisistedCells = append(listVisistedCells, otherCell)
			diagSum += mat[otherCell.x][otherCell.y]
		}
	}

	return diagSum
}

func getMinIndex(nums []int) int {
	idx := 0
	min := nums[0]

	for i, value := range nums {
		// If we have got the minimum value so far
		if value < min {
			min = value
			idx = i
		}
	}

	return idx
}

func checkIncRotaed(nums []int) bool {
	sliceLength := len(nums)
	isOkay := true

	if sliceLength == 0 {
		return isOkay
	}

	startIndex := getMinIndex(nums)
	itemCount := 0
	iterIndex := startIndex

	for itemCount < sliceLength-1 {
		// This means a rotation have happened, we need to see reset the scanning index
		if iterIndex == sliceLength-1 && startIndex != 0 {

			// Boundary condition
			if nums[0] < nums[sliceLength-1] {
				isOkay = false
				break
			}

			iterIndex = 0
			itemCount++
		} else if nums[iterIndex+1] < nums[iterIndex] {
			// The next number should always increase
			isOkay = false
			break
		}

		iterIndex++
		itemCount++
	}

	return isOkay
}
