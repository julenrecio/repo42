#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    if int(temp_str) < 0:
        raise ValueError(temp_str + "°C is too cold "
                         "for plants (min 0°C)")
    elif int(temp_str) > 40:
        raise ValueError(temp_str + "°C is too hot for "
                         "plants (max 40°C)")
    else:
        return (int(temp_str))


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===\n")
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
    try:
        print("Input data is '100'", sep="")
        value = input_temperature("100")
        print("Temperature is now ", value, "ºC", sep="")
    except ValueError as e:
        print("Caught input_temperature error:", e)
    print("")
    try:
        print("Input data is '-50'", sep="")
        value = input_temperature("-50")
        print("Temperature is now ", value, "ºC", sep="")
    except ValueError as e:
        print("Caught input_temperature error:", e)
    print("")
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
