#!/usr/bin/python3
"""
rain def
"""


def rain(walls=[]):
    """[rain func]

    Args:
        walls (list, optional): [array of walls]. Defaults to [].

    Returns:
        [type]: [number o rain accumlated]
    """
    if (not walls or len(walls) < 1):
        return 0
    n = len(walls)
    size = n - 1

    prev = walls[0]
    prev_i = 0
    rain = 0

    temp = 0
    for i in range(1, size + 1):
        if (walls[i] >= prev):
            prev = walls[i]
            prev_i = i
            temp = 0
        else:
            rain += prev - walls[i]
            temp += prev - walls[i]

    if (prev_i < size):
        rain -= temp
        prev = walls[size]

        for i in range(size, prev_i - 1, -1):
            if (walls[i] >= prev):
                prev = walls[i]
            else:
                rain += prev - walls[i]
    return rain
