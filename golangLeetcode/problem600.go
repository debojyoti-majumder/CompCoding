// Problem ID : 600

package main

import (
	"container/list"
	"fmt"
	"math"
)

var (
	binaryFormatNumber []bool
	stateQueue list.List
)

func getNumberCount() int {
	return 0
}

func getNonConsucutiveCount(number int) int {
	bitsRequired := 1
	if number > 0 {
		temp := math.Log2(float64(number))
		bitsRequired += int( math.Floor(temp) )
	}

	binaryFormatNumber = make([]bool, bitsRequired)
	return getNumberCount();
}

func main() { 
	fmt.Println(getNonConsucutiveCount(5))
}
