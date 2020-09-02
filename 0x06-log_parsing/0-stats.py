#!/usr/bin/python3
"""
Min operations
"""

import sys

try:
    count = 1
    fileSize = 0
    arrCodes = []
    for line in sys.stdin:
        actualLine = line.split()
        fileSize += int(actualLine[-1])
        arrCodes.append(int(actualLine[-2]))
        if (count == 10):
            print("File size: {}".format(fileSize))
            for item in sorted(arrCodes):
                print("{}: {}".format(item, arrCodes.count(item)))
            arrCodes = []
            count = 1
        count += 1
except (BrokenPipeError, IOError):
    pass
