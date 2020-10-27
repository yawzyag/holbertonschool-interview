#!/usr/bin/python3
"""
[find n posible queens]
"""

import sys
import math


def solveBoard(list_items, row, rowmask,
               ldmask, rdmask):

    n = len(list_items)

    all_rows_filled = (1 << n) - 1

    if (rowmask == all_rows_filled):
        j = 0
        list_final = []
        while j < len(list_items):
            k = 0
            while k < len(list_items[j]):
                if (list_items[j][k] == 1):
                    list_final.append([j, k])
                k += 1
            j += 1
        print(list_final)

    safe = all_rows_filled & (~(rowmask |
                                ldmask | rdmask))

    while (safe > 0):
        p = safe & (-safe)
        col = (int)(math.log(p)/math.log(2))
        list_items[row][col] = 1

        solveBoard(list_items, row+1, rowmask | p,
                   (ldmask | p) << 1, (rdmask | p) >> 1)

        safe = safe & (safe-1)

        list_items[row][col] = 0


if (len(sys.argv) != 2):
    print("Usage: nqueens N")
    sys.exit(1)
num = 0
try:
    num = int(sys.argv[1])
except:
    print("N must be a number")
    sys.exit(1)

if (num < 4):
    print("N must be at least 4")
    sys.exit(1)
list_items = []
i = 0
while i < num:
    list_items.append([0] * num)
    i += 1

solveBoard(list_items, 0, 0, 0, 0)
