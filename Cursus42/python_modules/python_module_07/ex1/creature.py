from .capabilities import HealCapability, TransformCapability
from ex0.creature import Creature


class Sproutling(Creature, HealCapability):

    def __init__(self) -> None:
        super().__init__("Sproutling", "Grass")

    def attack(self) -> str:
        return "{} uses Vine Whip!".format(self._name)

    def heal(self) -> str:
        return "{} heals itself for a small amount".format(self._name)


class Bloomelle(Creature, HealCapability):

    def __init__(self) -> None:
        super().__init__("Bloomelle", "Grass/Fairy")

    def attack(self) -> str:
        return "{} uses Petal Dance!".format(self._name)

    def heal(self) -> str:
        return ("{} heals itself and others for a large amount"
                .format(self._name))


class Shiftling(Creature, TransformCapability):

    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal")
        self._transformed = False

    def attack(self) -> str:
        if (self._transformed):
            return "{} performs a boosted strike!".format(self._name)
        else:
            return "{} attacks normally.".format(self._name)

    def transform(self) -> str:
        self._transformed = True
        return "{} shifts into a sharper form!".format(self._name)

    def revert(self) -> str:
        self._transformed = False
        return "{} returns to normal.".format(self._name)


class Morphagon(Creature, TransformCapability):

    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon")
        self._transformed: bool = False

    def attack(self) -> str:
        if (self._transformed):
            return ("{} unleashes a devastating morph strike!"
                    .format(self._name))
        else:
            return "{} attacks normally.".format(self._name)

    def transform(self) -> str:
        self._transformed = True
        return "{} morphs into a dragonic battle form!".format(self._name)

    def revert(self) -> str:
        self._transformed = False
        return "{} stabilizes its form.".format(self._name)
