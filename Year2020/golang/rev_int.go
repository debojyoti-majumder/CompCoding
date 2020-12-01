// Code URL: https://leetcode.com/problems/reverse-integer/submissions/

package main

import (
	"fmt"
	"math"
)

func reverse(x int) int {
	num := x
	is_negative := false
	
	// This was required for handling the negetive numbers 
	if x < 0 {
		is_negative = true
		num = num * -1
	}
	
	var digits [20]int8
	digit_count := 0
	
	// This is for digitizing the number
	for num > 0 {
		reminder := int8(num % 10)
		num = num - int(reminder)
		num = num / 10 
			
		digits[digit_count] = reminder
		digit_count = digit_count + 1	
	}
	digits[digit_count] = int8(num)
	
	num = 0
	for i:=0; i<digit_count; i++ {
		power_coff := float64(digit_count - i - 1)
		num += int(digits[i]) * int(math.Pow(10, power_coff))
	}
	
	if( is_negative ) {
		num = num * -1	
	}


	max_range := int(math.Pow(2,31))
	min_range := -1 * max_range
	if num >= max_range || num < min_range {
		return 0
	}
		
	return num    
}

func main() {
	fmt.Println(reverse(9022))
	fmt.Println(reverse(9020))
	fmt.Println(reverse(20))
	fmt.Println(reverse(-23))
	
	fmt.Println(reverse(-2))
	fmt.Println(reverse(8))
}
