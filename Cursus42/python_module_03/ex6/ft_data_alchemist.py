#!/usr/bin/env python3

import random

names: list = ['Alice', 'bob', 'Charlie', 'dylan', 'Emma',
               'Gregory', 'john', 'kevin', 'Liam']


def only_cap() -> list:
    newlist: list = [x for x in names if x == x.capitalize()]
    return newlist


def all_cap() -> list:
    newlist: list = [x.capitalize() for x in names]
    return newlist


def first_dict() -> dict:
    first: dict = {k: random.randint(0, 1000) for k in names}
    return first


def get_average(dictionary: dict) -> float:
    avg: int = 0
    for value in dictionary.values():
        avg += value
    return round((avg / len(dictionary)), 2)


def second_dict(first_dict: dict, average: float) -> dict:
    second_dict: dict = {k: first_dict[k] for k in
                         first_dict if first_dict[k] > average}
    return second_dict


if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")
    print("Initial list of players:", names)
    capitalized: list = all_cap()
    print("New list with all names capitalized:", capitalized)
    print("New list of capitalized names only:", only_cap())
    scores: dict = first_dict()
    print("Score dict", scores)
    average: float = get_average(scores)
    print("Score average is:", average)
    print("High scores:", second_dict(scores, average))
