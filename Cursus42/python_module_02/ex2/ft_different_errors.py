#!/usr/bin/env python3

def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        int("abc")
    elif (operation_number == 1):
        3 / 0
    elif (operation_number == 2):
        open("file.txt")
    elif (operation_number == 3):
        "abc" + 3
    else:
        return


def test_error_types(operation_number: int) -> None:
    try:
        print("Testing operation ", operation_number, "...", sep="")
        garden_operations(operation_number)
        print("Operation completed successfully")
    except ValueError as val:
        print("Caught ValueError:", val)
    except ZeroDivisionError as div:
        print("Caught ZeroDivisionError:", div)
    except FileNotFoundError as file:
        print("Caught FileNotFoundError:", file)
    except TypeError as typerr:
        print("Caught TypeError:", typerr)


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types(0)
    test_error_types(1)
    test_error_types(2)
    test_error_types(3)
    test_error_types(4)
    print("\nAll error types tested successfully!")
