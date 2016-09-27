#!/usr/bin/env python3
# https://open.kattis.com/problems/sumoftheothers
import sys
for line in sys.stdin.readlines():
	numbers = list(map(lambda x: int(x), line.rstrip().split(" ")))
	sum = 0;
	for n in numbers:
		sum += n;
	for n in numbers:
		if sum - n == n:
			print(n)
			break