#!/usr/bin/python3
"""
Validate utf8
"""


def count_leading_ones(byte):
    for i in range(8):
        if byte >> (7 - i) == 0b11111111 >> (7 - i) & ~1:
            return i
    return 8


def validUTF8(data):
    successive_10 = 0
    for b in data:
        b = bin(b).replace('0b','').rjust(8, '0')
        if successive_10 != 0:
            successive_10 -= 1
            if not b.startswith('10'):
                return False
        elif b[0] == '1':
                successive_10 = len(b.split('0')[0]) - 1
    return True
