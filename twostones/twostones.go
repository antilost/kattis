// https://open.kattis.com/problems/twostones

package main

import "fmt"

func main() {
	var stones_count uint32
	fmt.Scanf("%d", &stones_count)

	var winner string
	if stones_count % 2 == 0 {
		winner = "Bob"
	} else {
		winner = "Alice"
	}
	fmt.Println(winner)
}