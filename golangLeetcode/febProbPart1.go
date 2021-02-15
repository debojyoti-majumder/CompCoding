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
