#!/usr/bin/env python3

import sys

numbers = sorted([int(x) for x in sys.stdin.readline().split(' ')])
d = {}
for k, v in zip('ABC', numbers):
    d[k] = v
print(' '.join(['{}'.format(d[k]) for k in sys.stdin.readline().rstrip()]))
