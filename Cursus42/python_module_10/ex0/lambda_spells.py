#!/usr/bin/env python3

def artifact_sorter(artifacts: list[dict[str, str | int]]) -> list[dict[str, str | int]]:
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)
def power_filter(mages: list[dict[str, str | int]], min_power: int) -> list[dict[str, str | int]]:
    return list(filter(key=lambda x: x['power'] <= min_power, mages))
""" def spell_transformer(spells: list[str]) -> list[str]:
    pass
def mage_stats(mages: list[dict]) -> dict:
    pass """

if __name__ == "__main__":
    artifacts: list[dict[str, str | int]] = [{'name': 'Ice Wand', 'power': 99, 'type': 'relic'}, {'name': 'Fire Staff', 'power': 64, 'type': 'focus'}, {'name': 'Fire Staff', 'power': 106, 'type': 'focus'}, {'name': 'Lightning Rod', 'power': 71, 'type': 'weapon'}]
    mages: list[dict[str, str | int]] = [{'name': 'Morgan', 'power': 66, 'element': 'shadow'}, {'name': 'Casey', 'power': 64, 'element': 'wind'}, {'name': 'Sage', 'power': 70, 'element': 'wind'}, {'name': 'Sage', 'power': 75, 'element': 'fire'}, {'name': 'Ember', 'power': 75, 'element': 'lightning'}]
    spells: list[str] = ['fireball', 'darkness', 'tornado', 'blizzard']

    print(artifacts)
    print(artifact_sorter(artifacts))
    print(mages)
    print(power_filter(mages, 70))