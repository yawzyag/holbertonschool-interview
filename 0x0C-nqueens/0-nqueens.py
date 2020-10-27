#!/usr/bin/python3
"""
[find n posible queens]
"""

from sys import argv, exit


def ln(x):
    n = 1000.0
    return n * ((x ** (1/n)) - 1)


def solveBoard(list_items, row, rowmask,
               ldmask, rdmask):
    """[solve board]

    Args:
        list_items ([type]): [list of items in board]
        row ([type]): [row of board]
        rowmask ([type]): [mask]
        ldmask ([type]): [mask]
        rdmask ([type]): [mask]
    """

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
        col = (int)(ln(p)/ln(2))
        list_items[row][col] = 1

        solveBoard(list_items, row+1, rowmask | p,
                   (ldmask | p) << 1, (rdmask | p) >> 1)

        safe = safe & (safe-1)

        list_items[row][col] = 0


def main(argv):
    if (len(argv) != 2):
        print("Usage: nqueens N")
        exit(1)
    num = 0
    try:
        num = int(argv[1])
    except:
        print("N must be a number")
        exit(1)

    if (num < 4):
        print("N must be at least 4")
        exit(1)
    list_items = []
    i = 0
    while i < num:
        list_items.append([0] * num)
        i += 1

    solveBoard(list_items, 0, 0, 0, 0)


if __name__ == "__main__":
    main(argv)
