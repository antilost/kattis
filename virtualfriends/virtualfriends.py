#!/usr/bin/env python3

import sys

def find(x, P):
	if P[x] == x:
		return x
	else:
		P[x] = find(P[x], P)
		return P[x]

def unite(x, y, P, C):
	if x not in P:
		P[x] = x
		C[x] = 1

	if y not in P:
		P[y] = y
		C[y] = 1

	xp = find(x, P)
	yp = find(y, P)

	cx = C[xp]
	cy = C[yp]

	if xp == yp:
		return xp

	newp = None
	if cx > cy:
		newp = xp
		P[yp] = xp
	else:
		newp = yp
		P[xp] = yp
	C[newp] = cx + cy

	return newp

test_cases_count = int( sys.stdin.readline() )
for i in range(0, test_cases_count):
	connections_count = int( sys.stdin.readline() )
	P = {}
	C = {}
	for j in range(0, connections_count):
		(a, b) = sys.stdin.readline().rstrip().split(" ");
		print( C[unite(a, b, P, C)] )