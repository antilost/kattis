#!/usr/bin/env python2.7

from __future__ import print_function
import sys, os

test_cases_count = 1
while True:
	numbers_count = sys.stdin.readline().rstrip()
	if not numbers_count:
		break
	numbers_count = int(numbers_count)

	print('Case %d:' % test_cases_count)
	test_cases_count += 1

	numbers = []
	sums = set([]);
	for i in range(0, numbers_count):
		n = int(sys.stdin.readline().rstrip())
		if len(numbers) > 0:
			for prev_n in numbers:
				sums.add(prev_n + n)
		numbers.append(n)

	queris_count = int(sys.stdin.readline().rstrip())
	for i in range(0, queris_count):
		query = int(sys.stdin.readline().rstrip())
		(closest_sum, diff) = (None, None)
		for sum in sums:
			this_diff = abs(sum - query)
			if (diff is None) or (this_diff < diff):
				closest_sum = sum
				diff = this_diff
		print('Closest sum to %d is %d.' % (query, closest_sum))
