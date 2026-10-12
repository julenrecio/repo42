#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    argv: list = sys.argv
    argc: int = len(argv)
    print("=== Command Quest ===")
    print("Program name: {}".format(str(argv[0])))
    if (argc - 1 == 0):
        print("No arguments provided!")
    else:
        print("Arguments received: {}".format(argc - 1))
    i: int = 1
    while (i < argc):
        print("Argument " + str(i) + " : " + str(argv[i]))
        i += 1
    print("Total arguments: {}".format(argc))
