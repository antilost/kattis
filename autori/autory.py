#!/usr/bin/env python3

import sys

input = sys.stdin.readline()
for c in input:
    if c.istitle():
        print(c, end="")
print("")
