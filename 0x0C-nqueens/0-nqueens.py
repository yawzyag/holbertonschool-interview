#!/usr/bin/python3
"""
[find n posible queens]
"""

import sys
import math


def solveBoard(list_items, row, rowmask,
               ldmask, rdmask):

    n = len(list_items)

    # All_rows_filled is a bit mask
    # having all N bits set
    all_rows_filled = (1 << n) - 1

    # If rowmask will have all bits set, means
    # queen has been placed successfully
    # in all rows and list_items is diplayed
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

    # We extract a bit mask(safe) by rowmask,
    # ldmask and rdmask. all set bits of 'safe'
    # indicates the safe column index for queen
    # placement of this iteration for row index(row).
    safe = all_rows_filled & (~(rowmask |
                                ldmask | rdmask))

    while (safe > 0):

        # Extracts the right-most set bit
        # (safe column index) where queen
        # can be placed for this row
        p = safe & (-safe)
        col = (int)(math.log(p)/math.log(2))
        list_items[row][col] = 1

        # This is very important:
        # we need to update rowmask, ldmask and rdmask
        # for next row as safe index for queen placement
        # will be decided by these three bit masks.

        # We have all three rowmask, ldmask and
        # rdmask as 0 in beginning. Suppose, we are placing
        # queen at 1st column index at 0th row. rowmask, ldmask
        # and rdmask will change for next row as below:

        # rowmask's 1st bit will be set by OR operation
        # rowmask = 00000000000000000000000000000010

        # ldmask will change by setting 1st
        # bit by OR operation  and left shifting
        # by 1 as it has to block the next column
        # of next row because that will fall on left diagonal.
        # ldmask = 00000000000000000000000000000100

        # rdmask will change by setting 1st bit
        # by OR operation and right shifting by 1
        # as it has to block the previous column
        # of next row because that will fall on right diagonal.
        # rdmask = 00000000000000000000000000000001

        # these bit masks will keep updated in each
        # iteration for next row
        solveBoard(list_items, row+1, rowmask | p,
                   (ldmask | p) << 1, (rdmask | p) >> 1)

        # Reset right-most set bit to 0 so, next
        # iteration will continue by placing the queen
        # at another safe column index of this row
        safe = safe & (safe-1)

        # Backtracking, replace 'Q' by ' '
        list_items[row][col] = 0


def main(argv):
    if (len(argv) != 2):
        print("Usage: nqueens num")
        sys.exit(1)
    num = 0
    try:
        num = int(argv[1])
    except:
        print("num must be a number")
        sys.exit(1)

    if (num < 4):
        print("num must be at least 4")
        sys.exit(1)
    list_items = []
    i = 0
    while i < num:
        list_items.append([0] * num)
        i += 1

    solveBoard(list_items, 0, 0, 0, 0)


if __name__ == "__main__":
    main(sys.argv)
