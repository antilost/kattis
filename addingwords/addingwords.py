#!/usr/bin/env python3
import sys
C = {}
for line in sys.stdin.readlines():
	tokens = line.rstrip().split(' ')
	if tokens[0] == 'clear':
		C = {}
	elif tokens[0] == 'def':
		C[tokens[1]] = int(tokens[2])
	else:
#		print(tokens)
#		print(C)
		del(tokens[0])
		str = tokens[0]
		del(tokens[0])
		tokens.pop()
		if str not in C:
			flag = 1
		else:
			result = C[str]
			flag = 0
		while len(tokens) > 0:
#			print(tokens)
			op = tokens[0]
			del(tokens[0])
			id = tokens[0]
			del(tokens[0])
			str += (' ' + op + ' ' + id)
			if (flag == 1) or (id not in C):
				flag = 1
				continue
			if op == '-':
				result -= C[id]
			else:
				result += C[id]
		str_result = 'unknown'
		if flag == 0:
			for id in C.keys():
				if C[id] == result:
					str_result = id
					break
		print(str + ' = ' + str_result)
