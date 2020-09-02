#!/usr/bin/python3
"""Min operations"""
import sys


count = 0
fileSize = 0
arrCodes = [0, 0, 0, 0, 0, 0, 0, 0]
s = ["200", "301", "400", "401", "403", "404", "405", "500"]
try:
    for line in sys.stdin:
        actualLine = line.split(" ")
        if(len(actualLine) > 2):
            c = actualLine[-2]
            if c in s:
                i = s.index(c)
                arrCodes[i] += 1
            fileSize += int(actualLine[-1])
            count += 1
        if (count == 10):
            print("File size: {:d}".format(fileSize))
            i = 0
            while i < len(s):
                if (arrCodes[i] != 0):
                    print("{:}: {:d}".format(s[i], arrCodes[i]))
                i += 1
            count = 0
except Exception:
    pass
finally:
    print("File size: {:d}".format(fileSize))
    i = 0
    while i < len(s):
        if (arrCodes[i] != 0):
            print("{:}: {:d}".format(s[i], arrCodes[i]))
        i += 1
