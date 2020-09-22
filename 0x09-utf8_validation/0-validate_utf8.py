#!/usr/bin/python3
"""
Validate utf8
"""


def getLen(num):
    if (num >> 7 == 0):
        return 1
    if (num >> 5 == 0b110):
        return 2
    if (num >> 4 == 0b1110):
        return 3
    if (num >> 3 == 0b11110):
        return 4
    return -1


def validUTF8(data):
    i = 0
    for num in data:
        n = getLen(num)
        if (n == -1 or i + n > len(data)):
            return False
        i += 1
        while (n > 1):
            i += 1
            n -= 1
            if (data[i] >> 6 != 0b10):
                return False

    return True
