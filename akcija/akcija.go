/*
 * See task description at https://open.kattis.com/problems/akcija
 */

package main

import ("fmt" ; "sort")

func main() {
	// Input
	var n int // prices count (lines count)
	fmt.Scanf("%d", &n)
	prices := make([]int, n) // Make slice of n elements
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &prices[i]) // yet another price
	}

	sort.Sort( sort.Reverse( sort.IntSlice(prices) ) )

	var min_price int = 0
	for i := 0; i < n; i++ {
		if (i + 1) % 3 == 0 {
			continue
		}
		
		min_price += prices[i]
	}

	fmt.Println(min_price)
}