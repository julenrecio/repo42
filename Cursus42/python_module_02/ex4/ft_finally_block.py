#!/opt/pyenv/shims/python3

class GardenError(Exception):
    def __init__(self, message="Unknown garden error: "):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error: "):
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if (plant_name == plant_name.capitalize()):
        print("Watering", plant_name, ": [OK]")
    else:
        raise PlantError("Invalid plant name to water: '" + plant_name +
                         "' .. ending tests and returning to main")


def test_watering_system() -> None:
    print("=== Garden Watering System ===\n")
    print("Testing valid plants...")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrots")
    except PlantError as p:
        print("Caught PlantError:", p)
    finally:
        print("Closing watering system")
    print("\nTesting invalid plants...")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("lettuce")
        water_plant("Carrots")
    except PlantError as p:
        print("Caught PlantError:", p)
    finally:
        print("Closing watering system")
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
