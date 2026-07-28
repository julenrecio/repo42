#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    return (int(temp_str))


def test_temperature() -> None:
    print("=== Garden Temperature ===\n")
    try:
        print("Input data is '25'", sep="")
        value: int = input_temperature("25")
        print("Temperature is now ", value, "ºC", sep="")
    except ValueError as e:
        print("Caught input_temperature error:", e)
    print("")
    try:
        print("Input data is 'abc'", sep="")
        value = input_temperature("abc")
        print("Temperature is now ", value, "ºC", sep="")
    except ValueError as e:
        print("Caught input_temperature error:", e)
    print("")
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
