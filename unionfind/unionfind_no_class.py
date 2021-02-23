#!/usr/bin/env python3

import sys

class DisjointSet(object): # UnionFind
    def __init__(self, N):
        self.representative = {}
        for i in range(N):
            self.representative[i] = i

    def union(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        if rx < ry:
            self.representative[y] = rx
        elif ry < rx:
            self.representative[x] = ry

    def find(self, x):
        if self.representative[x] == x:
            return x
        else:
            self.representative[x] = self.find(self.representative[x])
            return self.representative[x]

    def is_connected(self, x, y):
        return self.find(x) == self.find(y)


(N, Q) = [int(x) for x in sys.stdin.readline().rstrip().split(' ')]
disjoint_set = DisjointSet(N)
for i in range(Q):
    (operation, x, y) = sys.stdin.readline().rstrip().split(' ')
    x = int(x)
    y = int(y)
    if operation == '=':
        disjoint_set.union(x, y)
    elif operation == '?':
        print('yes' if disjoint_set.is_connected(x, y) else 'no')
