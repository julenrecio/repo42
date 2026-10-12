#!/usr/bin/env python3

from typing import Any


def artifact_sorter(artifacts: list[dict[str, Any]]) -> list[dict[str, Any]]:
    return sorted(artifacts, key=lambda x: x["power"], reverse=True)


def power_filter(mages: list[dict[str, Any]],
                 min_power: int) -> list[dict[str, Any]]:
    return list(filter(lambda x: x["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: "* " + x + " *", spells))


def mage_stats(mages: list[dict[str, Any]]) -> dict[str, Any]:
    return {"max_power": max(map(lambda x: x["power"], mages)),
            "min_power": min(map(lambda x: x["power"], mages)),
            "avg_power": sum(map(lambda x: x["power"], mages)) / len(mages)}


if __name__ == "__main__":
    artifacts: list[dict[str, Any]] = [{'name': 'Ice Wand', 'power': 99,
                                        'type': 'relic'},
                                       {'name': 'Fire Staff', 'power': 64,
                                        'type': 'focus'},
                                       {'name': 'Fire Staff', 'power': 106,
                                        'type': 'focus'},
                                       {'name': 'Lightning Rod', 'power': 71,
                                        'type': 'weapon'}]

    mages: list[dict[str, Any]] = [{'name': 'Morgan', 'power': 66,
                                    'element': 'shadow'},
                                   {'name': 'Casey', 'power': 64,
                                    'element': 'wind'},
                                   {'name': 'Sage', 'power': 70,
                                    'element': 'wind'},
                                   {'name': 'Sage', 'power': 75,
                                    'element': 'fire'},
                                   {'name': 'Ember', 'power': 75,
                                    'element': 'lightning'}]

    spells: list[str] = ['fireball', 'darkness', 'tornado', 'blizzard']

    print("\nTesting artifact sorter...(descending sort by power)")
    print(artifact_sorter(artifacts))
    print("\nTesting power filter...(filtering power with min=70)")
    print(power_filter(mages, 70))
    print("\nTesting spell transformer...(transforming spell name with"
          "'* ' prefix and ' *' sufix)")
    print(spell_transformer(spells))
    print("\nTesting mage stats...(Obtaining mage stats with"
          "max, min, sum and len)")
    print(mage_stats(mages), "\n")
