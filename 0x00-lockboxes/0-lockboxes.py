#!/usr/bin/python3


def canUnlockAll(boxes):
    if (type(boxes) is not list or len(boxes) == 0):
        return False
    if (len(boxes[0]) == 0):
        return False
    keys = set()
    keys.add(0)
    alreadySee = set()
    i = 0
    while i < len(boxes):
        lenof = len(keys)
        if i not in alreadySee and i in keys:
            for num in boxes[i]:
                keys.add(num)
            alreadySee.add(i)
            if lenof < len(keys):
                i = 0
        i += 1

    if (len(alreadySee) == len(boxes)):
        return True
    return False
