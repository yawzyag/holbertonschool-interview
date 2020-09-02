#!/usr/bin/python3
"""
Min operations
"""
import sys

if __name__ == "__main__":
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
                finallCodes = sorted(arrCodes)
                for item in finallCodes:
                    print("{}: {}".format(item, arrCodes.count(item)))
                    finallCodes.remove(item)
                arrCodes = []
                count = 1
            count += 1
    except (BrokenPipeError, IOError):
        pass
