# https://open.kattis.com/problems/acm
import sys
buffer = {}
solved = {}
sum = 0
for line in sys.stdin.readlines():
	line = line.rstrip()
	if line == '-1':
		break
	(time, task, result) = line.split(" ")
	time = int(time)
	if result == 'right':
		if task in solved:
			continue
		solved[task] = 1
		sum += time
		if task in buffer:
			sum += buffer[task]
	else:
		if task not in buffer:
			buffer[task] = 0
		buffer[task] += 20

print(" ".join([ str(len(solved)), str(sum) ]))
