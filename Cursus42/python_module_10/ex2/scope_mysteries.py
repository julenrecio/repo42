#!/usr/bin/env python3

from collections.abc import Callable


def mage_counter() -> Callable[[], int]:
    count = 0

    def increment() -> int:
        nonlocal count
        count += 1
        return count
    return increment


def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    power = 100

    def accumulate(add_power: int) -> int:
        nonlocal power
        power += add_power
        return power
    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:

    def apply_enchantment(item_name: str) -> str:
        return enchantment_type + " " + item_name
    return apply_enchantment


def memory_vault() -> dict[str, Callable[..., object]]:
    vault: dict[str, str] = {}

    def store(key: str, value: str) -> None:
        vault[key] = value

    def recall(key: str) -> str:
        if (key in vault):
            return vault[key]
        else:
            return "Memory not found"
    return {'store': store, 'recall': recall}


if __name__ == "__main__":

    print("\nTesting mage counter...")
    counter_a = mage_counter()
    counter_b = mage_counter()
    print("counter_a call 1:", counter_a())
    print("counter_a call 2:", counter_a())
    print("counter_b call 1:", counter_b())

    print("\nTesting spell accumulator...")
    spell1 = spell_accumulator(10)
    print("Base 100, add 20:", spell1(20))
    print("Base 100, add 30:", spell1(30))

    print("\nTesting enchantment factory...")
    enchantment_factory1 = enchantment_factory("Flaming")
    print(enchantment_factory1("Sword"))
    enchantment_factory2 = enchantment_factory("Frozen")
    print(enchantment_factory2("Shield"))

    print("\nTesting memory vault...")
    vault1 = memory_vault()
    print("Store 'secret' = 42")
    vault1["store"]("secret", "42")
    print("Recall 'secret':", vault1["recall"]("secret"))
    print("Recall 'unknown':", vault1["recall"]("unknown"), "\n")
