#!/usr/bin/python3
"""Min operations"""
import sys


count = 0
fileSize = 0
arrCodes = []
status = ["200", "301", "400", "401", "403", "404", "405", "500"]
try:
    for line in sys.stdin:
        actualLine = line.split()
        if(len(actualLine) > 2):
            actualLine = line.split()
            fileSize += int(actualLine[-1])
            arrCodes.append(actualLine[-2])
            count += 1
        if (count == 10):
            print("File size: {:d}".format(fileSize))
            finallCodes = sorted(arrCodes)
            for item in finallCodes:
                if (status.count(item) != 0):
                    print("{:}: {:d}".format(item, arrCodes.count(item)))
                    finallCodes.remove(item)
            arrCodes = []
            count = 0
except Exception:
    pass
finally:
    print("File size: {:d}".format(fileSize))
    finallCodes = sorted(arrCodes)
    for item in finallCodes:
        if (status.count(item) != 0):
            print("{:}: {:d}".format(item, arrCodes.count(item)))
            finallCodes.remove(item)
