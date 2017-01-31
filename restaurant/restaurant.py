#!/usr/bin/env python3

import sys

processed_cases = 0
while True:
	cases_count = int(sys.stdin.readline())
	if cases_count == 0:
		break

	if processed_cases > 0:
		print("")

	p1 = 0
	p2 = 0
	for i in range(0, cases_count):
		(command, count) = sys.stdin.readline().split(" ")
		count = int(count)
		if command == "DROP":
			p1 += count
			print("DROP 1", count)
		if command == "TAKE":
			if count == 0:
				continue

			if p2 > 0:
				if p2 > count:
					print("TAKE 2", count)
					p2 -= count
					count = 0
				else:
					print("TAKE 2", p2)
					count -= p2
					p2 = 0
			if count > 0:
				print("MOVE 1->2", p1)
				p2 = p1
				p1 = 0
				print("TAKE 2", count)
				p2 -= count
	processed_cases += 1
