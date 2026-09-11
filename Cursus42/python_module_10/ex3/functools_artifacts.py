#!/usr/bin/env python3

from functools import reduce, partial, lru_cache, singledispatch
from operator import add, mul
from collections.abc import Callable
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if len(spells) == 0:
        return 0
    try:
        if (operation == "add"):
            return reduce(add, spells)
        elif (operation == "multiply"):
            return reduce(mul, spells)
        elif (operation == "max"):
            return reduce(lambda x, y: x if x > y else y, spells)
        elif (operation == "min"):
            return reduce(lambda x, y: x if x < y else y, spells)
        else:
            raise ValueError("Unknown operation: {}".format(operation))
    except ValueError as e:
        print(e)
        return 0


def partial_enchanter(base_enchantment: Callable[[int, str, str], str]
                      ) -> dict[str, Callable[[str], str]]:
    result: dict[str, Callable[[str], str]] = {}
    elements = ['fire', 'water', 'air']
    for element in elements:
        result[element] = partial(base_enchantment, 50, element)
    return result


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    else:
        return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:

    @singledispatch
    def dispatcher(value: Any) -> str:
        return "Unknown spell type: {}".format(type(value).__name__)

    @dispatcher.register(int)
    def damage_spell(damage: int) -> str:
        return "Damage spell: {} damage".format(str(damage))

    @dispatcher.register(str)
    def enchantment(enchantment: str) -> str:
        return "Enchantment: " + enchantment

    @dispatcher.register(list)
    def multi_cast(spells: list[Any]) -> str:
        return "Multi-cast: {} spells".format(len(spells))
    return dispatcher


if __name__ == "__main__":
    spell_powers = [27, 31, 24, 50, 11, 42]
    operations = ['add', 'multiply', 'max', 'min']
    fibonacci_tests = [9, 8, 10]

    print("\nTesting spell reducer...")
    print("Sum:", spell_reducer(spell_powers, operations[0]))
    print("Product:", spell_reducer(spell_powers, operations[1]))
    print("Max:", spell_reducer(spell_powers, operations[2]))
    print("Min:", spell_reducer(spell_powers, operations[3]))

    print("\nTesting partial enchanter...")

    def base_enchantment(power: int, element: str, target: str) -> str:
        return ("Enchantment of type {} hits {} with a power of {}."
                .format(element, target, power))
    partials = partial_enchanter(base_enchantment)
    for value in partials.values():
        print(value("mage"))

    print("\nTesting memoized fibonacci...")
    print("Fib(0):", memoized_fibonacci(0))
    print("Fib(1):", memoized_fibonacci(1))
    print("Fib(10):", memoized_fibonacci(10))
    print("Fib(15):", memoized_fibonacci(15))
    print("Fib(14):", memoized_fibonacci(14))
    print(memoized_fibonacci.cache_info())

    print("\nTesting spell dispatcher...")
    dispatcher = spell_dispatcher()
    print(dispatcher(42))
    print(dispatcher("fireball"))
    print(dispatcher([1, 2, 3]))
    print(dispatcher({"key": "value"}))
