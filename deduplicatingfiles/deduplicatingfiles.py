#!/usr/bin/env python3

# https://open.kattis.com/problems/deduplicatingfiles

import sys
import itertools

while True:
	n = int( sys.stdin.readline() )
	if n == 0:
		break

	file_to_hash = {}
	hashes_count = {}
	for i in range(0, n):
		file = sys.stdin.readline()[:-1]

		if file not in file_to_hash:
			file_to_hash[file] = 0
			for c in file:
				file_to_hash[file] ^= ord(c)
		hash = file_to_hash[file]

		if hash not in hashes_count:
			hashes_count[hash] = {}
		if file not in hashes_count[hash]:
			hashes_count[hash][file] = 0
		hashes_count[hash][file] += 1

	collizions_count = 0
	unique_files_count = 0
	for hash in hashes_count:
		unique_files_count += len(hashes_count[hash])
		for (f1, f2) in itertools.combinations( hashes_count[hash].keys(), 2 ):
			collizions_count += ( hashes_count[hash][f1] * hashes_count[hash][f2] )

	print( unique_files_count, collizions_count )
