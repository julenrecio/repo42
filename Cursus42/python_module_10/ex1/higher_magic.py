#!/usr/bin/env python3

from collections.abc import Callable


def spell_heal(target: str, power: int) -> str:
    return "Heal restores {} for {} HP.".format(target, power)


def spell_fireball(target: str, power: int) -> str:
    return ("Fireball launched toward {}! It deals {} points of burn damage "
            "and illuminates the area.".format(target, power))


def spell_shield(target: str, power: int) -> str:
    return ("A magical shield surrounds {}. It will absorb the next attacks"
            " for {} turns.".format(target, power))


def spell_shrink(target: str, power: int) -> str:
    return ("Shrink ray hits {}. Their physical size is immediately"
            " reduced by {}%.".format(target, power))


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
        return (base_spell(target, power * multiplier))
    return amplified_spell


def conditional_caster(condition: Callable[[str, int], bool],
                       spell: Callable[[str, int], str]
                       ) -> Callable[[str, int], str]:
    def conditional_spell(target: str, power: int) -> str:
        if (condition(target, power)):
            return spell(target, power)
        else:
            return "Spell fizzled"
    return conditional_spell


def condition(target: str, power: int) -> bool:
    if (power < 50 and target == "Dragon"):
        return True
    else:
        return False


def spell_sequence(spells: list[Callable[[str, int], str]]
                   ) -> Callable[[str, int], list[str]]:
    def sequence(target: str, power: int) -> list[str]:
        results: list[str] = []
        for spell in spells:
            results.append(spell(target, power))
        return results
    return sequence


if __name__ == "__main__":
    test_values = [20, 6, 23]
    test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']

    print("\nTesting spell combiner... (Returns a tuple with the spells"
          "combined, spells -> heal and fireball)")
    combiner = spell_combiner(spell_heal, spell_fireball)
    print(combiner(test_targets[0], test_values[0]))

    print("\nTesting power amplifier...(Returns a amplified spell, multiplier "
          "-> 5, 20 * 5 = 100)")
    amplifier = power_amplifier(spell_fireball, 5)
    print(amplifier(test_targets[0], test_values[0]))

    print("\nTesting conditional caster...(Returns a spell if condition -> "
          "power < 50 and target < 'Dragon')")
    conditional = conditional_caster(condition, spell_shield)
    print(conditional(test_targets[0], test_values[0]))

    print("\nTesting spell sequence...(Returns a list of spells -> "
          "heal, fireball, shield, mind_control, spell_shrink)")
    sequence = spell_sequence([spell_heal, spell_fireball,
                               spell_shield, spell_mind_control, spell_shrink])
    print(sequence(test_targets[0], test_values[0]), "\n")
