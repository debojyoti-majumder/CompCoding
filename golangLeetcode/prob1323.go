func maximum69Number(num int) int {
	testNum := num
	pos := 0
	numberLength := 0
	tobeReplaced := false

	// This is base case just to be sure
	if num == 6 || num == 9 {
		return 9
	}

	for testNum > 0 {
		digit := testNum % 10

		if digit == 6 {
			pos = numberLength
			tobeReplaced = true
		}

		numberLength++
		testNum /= 10
	}

	if tobeReplaced {
		// As we know the number is always an integer
		opNumber := int(math.Pow10(pos))

		// This would replace the 6 with 9
		num += (opNumber * 3)
	}

	return num
}
