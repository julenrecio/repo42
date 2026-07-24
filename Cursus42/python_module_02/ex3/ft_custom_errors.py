#!/opt/pyenv/shims/python3

class GardenError(Exception):
    def __init__(self, message="Unknown garden error: "):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error: "):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message="Unknown water error: "):
        super().__init__(message)


def raise_exceptions(tomato_wilting: bool, water: int) -> None:
    if (tomato_wilting):
        raise PlantError("The tomato plant is wilting!")
    if (water < 10):
        raise WaterError("Not enough water in the tank!")


def test_garden_errors() -> None:
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        raise_exceptions(True, 15)
    except PlantError as p:
        print("Caught PlantError:", p)
    print("")

    print("Testing WaterError...")
    try:
        raise_exceptions(False, 5)
    except WaterError as w:
        print("Caught WaterError:", w)
    print("")

    print("Testing catching all garden errors...")
    try:
        raise_exceptions(True, 15)
    except GardenError as g:
        print("Caught GardenError:", g)
    try:
        raise_exceptions(False, 5)
    except GardenError as g:
        print("Caught GardenError:", g)

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    test_garden_errors()
