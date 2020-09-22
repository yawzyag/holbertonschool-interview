#!/usr/bin/python3
"""
Validate utf8
"""


def validUTF8(data):
    left = 0
    for d in data:
        if (left == 0):
            if ((d >> 3) == 0b11110):
                left = 3
            elif ((d >> 4) == 0b1110):
                left = 2
            elif ((d >> 5) == 0b110):
                left = 1
            elif ((d >> 7) == 0b0):
                left = 0
            else:
                return False
        else:
            if ((d >> 6) != 0b10):
                return False
            left -= 1
    return left == 0
