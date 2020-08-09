#!/usr/bin/python3
"""
Min operations
"""


def minOperations(n=0):
    """ comment """
    if (n < 2):
        return 0
    copy = 1
    operations_count = 1
    paste = 1
    while(paste < n):
        paste += copy
        if (n % paste == 0 and paste < n):
            copy = paste
            operations_count += 1
        operations_count += 1
    return operations_count
