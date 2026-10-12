#!/usr/bin/env python3

from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex1.creature import Sproutling, Bloomelle, Shiftling, Morphagon

if __name__ == "__main__":
    healing: HealingCreatureFactory = HealingCreatureFactory()
    transform: TransformCreatureFactory = TransformCreatureFactory()
    healing_base: Sproutling = healing.create_base()
    healing_evolved: Bloomelle = healing.create_evolved()
    transform_base: Shiftling = transform.create_base()
    transform_evolved: Morphagon = transform.create_evolved()
    print("Testing Creature with healing capability")
    print(" base:")
    print(healing_base.describe())
    print(healing_base.attack())
    print(healing_base.heal())
    print(" evolved:")
    print(healing_evolved.describe())
    print(healing_evolved.attack())
    print(healing_evolved.heal())
    print("\nTesting Creature with transform capability")
    print(" base:")
    print(transform_base.describe())
    print(transform_base.attack())
    print(transform_base.transform())
    print(transform_base.attack())
    print(transform_base.revert())
    print(" evolved:")
    print(transform_evolved.describe())
    print(transform_evolved.attack())
    print(transform_evolved.transform())
    print(transform_evolved.attack())
    print(transform_evolved.revert())
