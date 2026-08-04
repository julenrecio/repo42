#!/usr/bin/env python3

import sys
import typing


def get_file() -> None:
    if (len(sys.argv) != 2):
        print("Usage: ft_ancient_text.py <file>")
    else:
        try:
            print("=== Cyber Archives Recovery ===")
            filename: str = sys.argv[1]
            print("Accessing file '{}'".format(filename))
            file1: typing.IO = open(filename, 'r')
            print("---\n")
            content = file1.read()
            print(content)
            print("\n---")
            file1.close()
            print("File '{}' closed.".format(filename))
        except FileNotFoundError as f:
            print("Error opening file '{}':".format(filename), f)
        except PermissionError as p:
            print("Error opening file '{}':".format(filename), p)


if __name__ == "__main__":
    get_file()
