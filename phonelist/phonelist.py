#!/usr/bin/env python3

import sys

test_cases_count = int(sys.stdin.readline())

for i in range(test_cases_count):
    phone_numbers_count = int(sys.stdin.readline())
    answer = 'YES'
    trie = {}
    for j in range(phone_numbers_count):
        phone_number = sys.stdin.readline().rstrip()

        if answer == 'NO':
            continue

        node = trie
        for d in list(phone_number):
            if 'ended' in node:
                answer = 'NO'
                break
            if d not in node:
                node[d] = {}
            node = node[d]

        if answer == 'NO':
            continue

        node['ended'] = True
        if len(node.keys()) > 1:
            answer = 'NO'

    print(answer)
