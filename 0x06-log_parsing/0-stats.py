#!/usr/bin/python3
"""Min operations"""
import sys


count = 1
fileSize = 0
arrCodes = []
status = [200, 301, 400, 401, 403, 404, 405, 500]
try:
    for line in sys.stdin:
        actualLine = line.split()
        if(len(actualLine) > 2):
            actualLine = line.split()
            fileSize += int(actualLine[-1])
            arrCodes.append(int(actualLine[-2]))
            if (count == 10):
                print("File size: {}".format(fileSize))
                finallCodes = sorted(arrCodes)
                for item in finallCodes:
                    if (status.count(item) != 0):
                        print("{}: {}".format(item, arrCodes.count(item)))
                        finallCodes.remove(item)
                arrCodes = []
                count = 1
            count += 1
except Exception:
    pass
finally:
    print("File size: {}".format(fileSize))
    finallCodes = sorted(arrCodes)
    for item in finallCodes:
        if (status.count(item) != 0):
            print("{}: {}".format(item, arrCodes.count(item)))
            finallCodes.remove(item)
