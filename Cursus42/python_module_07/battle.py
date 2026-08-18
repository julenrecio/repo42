from ex0 import FlameFactory, AquaFactory, CreatureFactory


def check_factory(factory: CreatureFactory) -> None:
    print(factory.create_base().describe())
    print(factory.create_base().attack())
    print(factory.create_evolved().describe())
    print(factory.create_evolved().attack())


def fight(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    print(factory1.create_base().describe())
    print(" vs.")
    print(factory2.create_base().describe())
    print(" fight!")
    print(factory1.create_base().attack())
    print(factory2.create_base().attack())


if __name__ == "__main__":
    flame: FlameFactory = FlameFactory()
    aqua: AquaFactory = AquaFactory()
    print("Testing factory")
    check_factory(flame)
    print("\nTesting factory")
    check_factory(aqua)
    print("\nTesting battle")
    fight(flame, aqua)
