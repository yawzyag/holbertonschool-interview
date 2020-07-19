#!/usr/bin/python3


def canUnlockAll(boxes):
    if (type(boxes) is not list or len(boxes) == 0):
        return False
    if (len(boxes[0]) == 0):
        return False
    keys = set()
    keys.add(0)

    i = 0
    while i < len(boxes):
        for num in boxes[i]:
            if i in keys and num < len(boxes) and num > 0:
                keys.add(num)
        i += 1

    if (len(keys) == len(boxes) or len(keys) == (len(boxes) - 1)):
        return True
    return False
