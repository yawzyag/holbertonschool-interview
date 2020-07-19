#!/usr/bin/python3


def canUnlockAll(boxes):
    if (type(boxes) is not list or len(boxes) == 0):
        return False
    if (len(boxes[0]) == 0):
        return False
    keys = set()
    keys.add(0)
    alreadySee = set()

    print(boxes)
    i = 0
    while i < len(boxes):
        if i in keys and i not in alreadySee:
            for num in boxes[i]:
                if num > 0 and num < len(boxes):
                    keys.add(num)
            alreadySee.add(i);
        i += 1
    print(keys, alreadySee, len(boxes))
    if (len(keys) == len(boxes) or len(keys) == (len(boxes) - 1)):
        return True
    return False
