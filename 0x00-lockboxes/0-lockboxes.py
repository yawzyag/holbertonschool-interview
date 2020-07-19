#!/usr/bin/python3


def canUnlockAll(boxes):
    if (type(boxes) is not list or len(boxes) == 0):
        return False
    if (len(boxes[0]) == 0):
        return False
    keys = set()
    keys.update(boxes[0])
    alreadySee = set()

    i = 0
    while i < len(boxes):
        for num in boxes[i]:
            if i in keys and i not in alreadySee:
                keys.add(num)
                alreadySee.add(i)
                i = 0
                break
        i += 1

    if (len(keys) == len(boxes) or len(keys) == (len(boxes) - 1)):
        return True
    return False
