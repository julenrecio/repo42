#!/usr/bin/env python3

from collections.abc import Callable

def mage_counter() -> Callable[[], int]:
    count = 0
    def increment():
        nonlocal count
        count += 1
        return count
    return increment


def spell_accumulator(initial_power: int) -> Callable[[], int]:
    power = initial_power
    def accumulate():
        nonlocal power
        power += initial_power
        return power
    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable[[], str]:
    enchantment = "Sword"
    def apply_enchantment():
        nonlocal enchantment
        enchantment = enchantment_type + " " +  enchantment
        return enchantment
    return apply_enchantment


""" def memory_vault() -> dict[str, Callable] """


""" spell1 = spell_accumulator(10)
print(spell1())
print(spell1()) """
enchantment_factory1 = enchantment_factory("Flaming")
print(enchantment_factory1())
print(enchantment_factory1())
print(enchantment_factory1())