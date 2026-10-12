#!/usr/bin/env python3

from ex0 import FlameFactory, AquaFactory, CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (NormalStrategy, AggresiveStrategy,
                 DefensiveStrategy, BattleStrategy)
from ex0.creature import Creature


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("[ ", end="")
    for i in range(len(opponents)):
        strat: str
        name: str
        if isinstance(opponents[i][1], NormalStrategy):
            strat = "Normal"
        elif isinstance(opponents[i][1], AggresiveStrategy):
            strat = "Aggresive"
        else:
            strat = "Defensive"
        if isinstance(opponents[i][0], HealingCreatureFactory):
            name = "Healing"
        elif isinstance(opponents[i][0], TransformCreatureFactory):
            name = "Transform"
        else:
            name = opponents[i][0].create_base().get_name()
        if i < (len(opponents) - 1):
            print("({}+{}), ".format(name, strat), end="")
        else:
            print("({}+{})".format(name, strat), end="")
    print(" ]")
    print("*** Tournament ***")
    print("{} opponents involved".format(len(opponents)))
    for i in range(len(opponents)):
        for j in range(i + 1, len(opponents)):
            print("\n* Battle *")
            opponent1: Creature = opponents[i][0].create_base()
            opponent2: Creature = opponents[j][0].create_base()
            strat1: BattleStrategy = opponents[i][1]
            strat2: BattleStrategy = opponents[j][1]
            print(opponent1.describe())
            print(" vs.")
            print(opponent2.describe())
            print(" now fight!")
            try:
                strat1.act(opponent1)
                strat2.act(opponent2)
            except Exception as e:
                print(e)


if __name__ == "__main__":
    flame: FlameFactory = FlameFactory()
    aqua: AquaFactory = AquaFactory()
    healing: HealingCreatureFactory = HealingCreatureFactory()
    transform: TransformCreatureFactory = TransformCreatureFactory()
    normal: NormalStrategy = NormalStrategy()
    aggresive: AggresiveStrategy = AggresiveStrategy()
    defensive: DefensiveStrategy = DefensiveStrategy()
    battle1: list[tuple[CreatureFactory, BattleStrategy]]
    battle2: list[tuple[CreatureFactory, BattleStrategy]]
    battle3: list[tuple[CreatureFactory, BattleStrategy]]
    battle1 = [(flame, normal), (healing, defensive)]
    battle2 = [(flame, aggresive), (healing, defensive)]
    battle3 = [(aqua, normal), (healing, defensive), (transform, aggresive)]
    print("Tournament 0 (basic)")
    battle(battle1)
    print("\nTournament 1 (error)")
    battle(battle2)
    print("\nTournament 2 (multiple)")
    battle(battle3)
