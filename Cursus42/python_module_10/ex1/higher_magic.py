#!/usr/bin/env python3

from collections.abc import Callable


def spell_heal(target: str, power: int) -> str:
    return "Heal restores {} for {} HP.".format(target, power)


def spell_fireball(target: str, power: int) -> str:
    return ("Fireball launched toward {}! It deals {} points of burn damage and"
            " illuminates the area.".format(target, power))


def spell_shield(target: str, power: int) -> str:
    return ("A magical shield surrounds {}. It will absorb the next attacks"
            "for {} turns.".format(target, power))


def spell_shrink(target: str, power: int) -> str:
    return ("Shrink ray hits {}. Their physical size is immediately"
            "reduced by {}%.".format(target, power))


def spell_mind_control(target: str, power: int) -> str:
    return ("Mystical whispers invade {}'s mind. Successful mind control"
            " chance: {}%.".format(target, power))


def spell_combiner(spell1: Callable[[str, int], str],
                   spell2: Callable[[str, int], str]
                   ) -> Callable[[str, int], tuple[str, str]]:
    def combined_spell(target: str, power: int) -> tuple[str, str]:
        return (spell1(target, power), spell2(target, power))
    return combined_spell


def power_amplifier(base_spell: Callable[[str, int], str], multiplier: int
                    ) -> Callable[[str, int], str]:
    def amplified_spell(target: str, power: int) -> str:
        return(base_spell(target, power * multiplier))
    return amplified_spell


""" def conditional_caster(condition: Callable[[str, int], bool], spell: Callable[[str, int], str]) -> Callable[[str, int], str]:
    def conditional(target: str, power: int) -> str:
        if (condition):
            return True
        else:
            return False
    def spell(target: str, power: int) """


""" def spell_sequence(spells: list[Callable]) -> Callable """

test_values = [20, 6, 23]
test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']

combiner = spell_combiner(spell_heal, spell_fireball)
print(combiner(test_targets[0], test_values[0]))
amplifier = power_amplifier(spell_fireball, 5)
print(amplifier(test_targets[0], test_values[0]))
