// https://open.kattis.com/problems/collatz

package main

import "fmt"

func main() {
	var A, B, a, b uint64
	var steps_a, steps_b uint32
	var steps map[uint64]uint32
	for true {
		fmt.Scanf("%d", &A)
		fmt.Scanf("%d", &B)
		if ( (A == 0) && (B == 0) ) {
			break
		}

		steps = make(map[uint64]uint32)

		a = A
		steps_a = 0
		steps[a] = steps_a
		for (a != 1) {
			if ( (a & 1) > 0) {
				a = a + a + a + 1
			} else {
				a = a >> 1
			}
			steps_a++
			steps[a] = steps_a
		}

		b = B
		steps_b = 0
		for true {
			_, ok := steps[b]
			if (ok) {
				steps_a = steps[b]
				break
			}

			if ( (b & 1) > 0) {
				b = b + b + b + 1
			} else {
				b = b >> 1
			}

			steps_b++
		}

		fmt.Printf("%d needs %d steps, %d needs %d steps, they meet at %d\n", A, steps_a, B, steps_b, b)
	}
}