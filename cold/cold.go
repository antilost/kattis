package main

import "fmt"

func main() {
	var numbers_count uint8
	fmt.Scanf("%d", &numbers_count)

	var less_zero_numbers_count uint8 = 0
	for numbers_count > 0 {
		numbers_count--

		var number int64;
		fmt.Scanf("%d", &number);
		if number < 0 {
			less_zero_numbers_count++
		}
	}

	fmt.Println(less_zero_numbers_count)
}