from ex0 import FlameFactory, AquaFactory, CreatureFactory
from ex0.creature import Creature


def check_factory(factory: CreatureFactory) -> None:
    base: Creature = factory.create_base()
    evolved: Creature = factory.create_evolved()
    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())


def fight(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    base_f1: Creature = factory1.create_base()
    base_f2: Creature = factory2.create_base()
    print(base_f1.describe())
    print(" vs.")
    print(base_f2.describe())
    print(" fight!")
    print(base_f1.attack())
    print(base_f2.attack())


if __name__ == "__main__":
    flame: FlameFactory = FlameFactory()
    aqua: AquaFactory = AquaFactory()
    print("Testing factory")
    check_factory(flame)
    print("\nTesting factory")
    check_factory(aqua)
    print("\nTesting battle")
    fight(flame, aqua)
