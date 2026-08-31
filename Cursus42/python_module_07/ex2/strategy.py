from typing import cast
from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.capabilities import HealCapability, TransformCapability


class BattleStrategy(ABC):

    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        if creature:
            return True
        else:
            return False

    def act(self, creature: Creature) -> None:
        if self.is_valid(creature):
            print(creature.attack())
        else:
            raise Exception("Battle error, aborting tournament: "
                            "Invalid Creature '{}' for this aggresive "
                            "strategy".format(creature.get_name()))


class AggresiveStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, TransformCapability):
            return True
        else:
            return False

    def act(self, creature: Creature) -> None:
        if self.is_valid(creature):
            print(cast(TransformCapability, creature).transform())
            print(creature.attack())
            print(cast(TransformCapability, creature).revert())
        else:
            raise Exception("Battle error, aborting tournament: "
                            "Invalid Creature '{}' for this aggresive "
                            "strategy".format(creature.get_name()))


class DefensiveStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, HealCapability):
            return True
        else:
            return False

    def act(self, creature: Creature) -> None:
        if self.is_valid(creature):
            print(creature.attack())
            print(cast(HealCapability, creature).heal())
        else:
            raise Exception("Battle error, aborting tournament: "
                            "Invalid Creature '{}' for this defensive "
                            "strategy".format(creature.get_name()))
