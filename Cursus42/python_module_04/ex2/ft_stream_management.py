#!/usr/bin/env python3

import sys
import typing


def get_file() -> None:
    if (len(sys.argv) != 2):
        sys.stdout.write("Usage: ft_ancient_text.py <file>")
    else:
        try:
            sys.stdout.write("=== Cyber Archives Recovery & Preservation ===")
            sys.stdout.write("\n")
            filename: str = sys.argv[1]
            sys.stdout.write("Accessing file '{}'\n".format(filename))
            file1: typing.IO = open(filename, 'r')
            content = file1.read()
            sys.stdout.write("---\n\n")
            sys.stdout.write(content)
            sys.stdout.write("\n\n---\n")
            file1.close()
            sys.stdout.write("File '{}' closed.\n".format(filename))
            sys.stdout.write("\nTransform data:\n")
            content = content.replace("\n", "#\n")
            if not content.endswith("#\n"):
                content += "#"
            sys.stdout.write("---\n\n")
            sys.stdout.write(content)
            sys.stdout.write("\n\n---\n")
            sys.stdout.write("Enter new file name (or empty): ")
            sys.stdout.flush()
            save_filename: str = sys.stdin.readline().strip()
            if (save_filename != ""):
                sys.stdout.write("Saving data to '{}'\n".format(save_filename))
                file2: typing.IO = open(save_filename, 'w')
                file2.write(content)
                file2.close()
                sys.stdout.write("Data saved in file '{}'"
                                 .format(save_filename))
            else:
                sys.stdout.write("Not saving data.")
        except FileNotFoundError as f:
            sys.stderr.write("[STDERR] Error opening file '{}': {}".
                             format(filename, str(f)))
        except PermissionError as p:
            sys.stderr.write("[STDERR] Error opening file '{}': {}".
                             format(save_filename, str(p)))
            sys.stderr.flush()
            sys.stdout.write("\nData not saved.")


if __name__ == "__main__":
    get_file()
