#!/opt/pyenv/shims/python3

class Plant:

    def __init__(self, name: str, height: float,
                 age: int, growth_per_day: float) -> None:
        self._name = name
        if (height > 0.0):
            self._height = height
        else:
            self._height = 1.0
            print(self._name, ": Create error, height can't be negative, "
                  "height set to default", sep="")
        if (age > 0):
            self._age = age
        else:
            self._age = 1
            print(self._name, ": Create error, age can't be negative, "
                  "age set to default", sep="")
        if (growth_per_day > 0.0):
            self._growth_per_day = growth_per_day
        else:
            self._growth_per_day = 1.0
            print(self._name, ": Create error, growth per day can't "
                  "be negative, growth per day set to default", sep="")

    def show_extra(self) -> str:
        return ""

    def show(self) -> None:
        print(self._name, ": ", self._height,
              "cm, ", self._age, " days old, ", self._growth_per_day,
              " growth rate, ", self.show_extra(), sep="")

    def aging(self) -> None:
        self.set_age(self._age + 1)

    def grow(self) -> None:
        self.set_height(round(self._height + self._growth_per_day, 2))

    def set_height(self, height: float) -> None:
        if (height > 0.0):
            self._height = height
        else:
            print(self._name, ": Update error, height can't be negative, "
                  "height update rejected", sep="")

    def set_age(self, age: int) -> None:
        if (age > 0):
            self._age = age
        else:
            print(self._name, ": Update error, age can't be negative, "
                  "age update rejected", sep="")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, color: str) -> None:
        super().__init__(name, height, age, growth_per_day)
        self._color = color

    def bloom(self) -> None:
        print(self._name + " is blooming beautifully!")

    def show_extra(self) -> str:
        return self._color + " color"


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, trunk_diameter: float) -> None:
        super().__init__(name, height, age, growth_per_day)
        self._trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print("Tree", self._name, "now produces a shade of", self._height,
              "cm long and", self._trunk_diameter, "cm wide.")

    def show_extra(self) -> str:
        return str(self._trunk_diameter) + " trunk diameter"


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, harvest_season: str,
                 nutritional_value: int) -> None:
        super().__init__(name, height, age, growth_per_day)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show_extra(self) -> str:
        return ("harvest season: " + self._harvest_season +
                ", nutritional value: " + str(self._nutritional_value))

    def grow(self) -> None:
        super().grow()
        self._nutritional_value += 1

    def aging(self) -> None:
        super().aging()
        self._nutritional_value += 1


if __name__ == "__main__":

    print("=== Garden Plant Types ===\n")

    print("=== Flower")
    flower: Flower = Flower("Rose", 15.0, 10, 3.3, "red")
    flower.show()
    print("[asking the rose to bloom]")
    flower.bloom()
    print("")

    print("=== Tree")
    tree: Tree = Tree("Oak", 200.0, 365, 1.2, 5.0)
    tree.show()
    print("[asking the oak to produce shade]")
    tree.produce_shade()
    print("")

    print("=== Vegetable")
    vegetable: Vegetable = Vegetable("Tomato", 47.0, 30, 5.6, "april", 0)
    vegetable.show()
    print("[make tomato grow and age for 20 days]")
    for _ in range(0, 20):
        vegetable.grow()
        vegetable.aging()
    vegetable.show()
