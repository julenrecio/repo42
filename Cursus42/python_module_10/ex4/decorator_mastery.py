#!/usr/bin/env python3

from functools import wraps
from collections.abc import Callable
from typing import Any
import time


def spell_timer(func: Callable[[str, int], str]) -> Callable[[str, int], str]:
    @wraps(func)
    def wrapper(name: str, power: int) -> str:
        print("Casting {}...".format(name))
        start_time = time.time()
        time.sleep(0.042)
        result = func(name, power)
        end_time = time.time()
        print(f"Spell completed in {end_time - start_time:.3f} seconds")
        print("Result: {} cast!".format(name.capitalize()))
        return result
    return wrapper


@spell_timer
def spell1(name: str, power: int) -> str:
    return ("Casted {} spell with a power of {}."
            .format(name, power))


def power_validator(min_power: int) -> Callable[..., Any]:
    def decorator(func: Callable[..., Any]) -> Callable[..., Any]:
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs.get("power")
            if power is None:
                power = args[-1]
            if (power < min_power):
                return "Insufficient power for this spell"
            return func(*args, **kwargs)
        return wrapper
    return decorator


@power_validator(50)
def spell2(name: str, power: int) -> str:
    return ("Casted {} spell with a power of {}."
            .format(name, power))


def retry_spell(max_attempts: int
                ) -> Callable[[Callable[[str, int], str]],
                              Callable[[str, int], str]]:
    def decorator(func: Callable[[str, int], str]
                  ) -> Callable[[str, int], str]:
        def wrapper(name: str, power: int) -> str:
            attemps: int = 0
            while attemps < max_attempts:
                try:
                    return func(name, power)
                except ValueError:
                    attemps += 1
                    if attemps != max_attempts:
                        print("Spell failed, retrying... (attempt {}/{})"
                              .format(attemps, max_attempts))
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


@retry_spell(3)
def spell3(name: str, power: int) -> str:
    raise ValueError("Something went wrong")


@retry_spell(3)
def spell4(name: str, power: int) -> str:
    return ("{} spelled !".format(name))


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) > 3 and all(c.isalnum() or c.isspace() for c in name):
            return True
        else:
            return False

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return ("Successfully cast {} with {} power"
                .format(spell_name, power))


if __name__ == "__main__":
    print("\nTesting spell timer...")
    spell1("fireball", 50)

    print("\nTesting power validator...")
    print(spell2("fireball", 42))
    print(spell2("fireball", 84))

    print("\nTesting retrying spell...")
    print(spell3("fireball", 50))
    print(spell4("Waaaaaaagh", 50))

    print("\nTesting MageGuild...")
    print(MageGuild.validate_mage_name("albert"))
    print(MageGuild.validate_mage_name("al"))
    mageguild: MageGuild = MageGuild()
    print(mageguild.cast_spell("Lightning", 15))
    print(mageguild.cast_spell("Lightning", 8), "\n")
