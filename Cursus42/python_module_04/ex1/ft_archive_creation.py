#!/usr/bin/env python3

import sys
import typing


def get_file() -> None:
    if (len(sys.argv) != 2):
        print("Usage: ft_ancient_text.py <file>")
    else:
        try:
            print("=== Cyber Archives Recovery & Preservation ===")
            filename: str = sys.argv[1]
            print("Accessing file '{}'".format(filename))
            file1: typing.IO = open(filename, 'r')
            content: str = file1.read()
            print("---\n")
            print(content)
            print("\n---")
            file1.close()
            print("File '{}' closed.".format(filename))
            print("\nTransform data:")
            content = content.replace("\n", "#\n")
            if not content.endswith("#\n"):
                content += "#"
            print("---\n")
            print(content)
            print("\n---")
            save_filename: str = input("Enter new file name (or empty): ")
            if (save_filename != ""):
                print("Saving data to '{}'".format(save_filename))
                file2: typing.IO = open(save_filename, 'w')
                file2.write(content)
                file2.close()
                print("Data saved in file '{}'".format(save_filename))
            else:
                print("Not saving data.")
        except FileNotFoundError as f:
            print("Error opening file '{}':".format(filename), f)
        except PermissionError as p:
            print("Error opening file '{}':".format(filename), p)


if __name__ == "__main__":
    get_file()
