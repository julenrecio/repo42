#!/usr/bin/env python3

import random


def gen_player_achievements(achievements: list) -> set:
    num_achievements = random.randint(0, len(achievements))
    player: set = set()
    for i in range(num_achievements):
        achievement_number = random.randint(0, len(achievements) - 1)
        player.add(achievements[achievement_number])
    return player


if __name__ == "__main__":
    achievements: list = ['Crafting Genius', 'Strategist', 'World Savior',
                          'Speed Runner', 'Survivor', 'Master Explorer',
                          'Treasure Hunter', 'Unstoppable', 'First Steps',
                          'Collector Supreme', 'Untouchable', 'Sharp Mind',
                          'Boss Slayer', 'extra1', 'extra2', 'extra3']
    alice: set = gen_player_achievements(achievements)
    bob: set = gen_player_achievements(achievements)
    charlie: set = gen_player_achievements(achievements)
    dylan: set = gen_player_achievements(achievements)
    print("Player alice: " + str(alice))
    print("Player bob: " + str(bob))
    print("Player charlie: " + str(charlie))
    print("Player dylan: " + str(dylan))
    print("All distinct achievements: " +
          str(alice.union(bob).union(charlie).union(dylan)))
    print("Common achievements: " +
          str(alice.intersection(bob).intersection(charlie).
              intersection(dylan)))
    print("Only Alice has: " +
          str(alice.difference(bob).difference(charlie).difference(dylan)))
    print("Only Bob has: " +
          str(bob.difference(alice).difference(charlie).difference(dylan)))
    print("Only Charlie has: " +
          str(charlie.difference(alice).difference(bob).difference(dylan)))
    print("Only Dylan has: " +
          str(dylan.difference(alice).difference(bob).difference(charlie)))
    print("Alice is missing: " + str(set(achievements).difference(alice)))
    print("Bob is missing: " + str(set(achievements).difference(bob)))
    print("Charlie is missing: " + str(set(achievements).difference(charlie)))
    print("Dylan is missing: " + str(set(achievements).difference(dylan)))
