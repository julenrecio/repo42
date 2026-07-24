#!/opt/pyenv/shims/python3

class Plant:

    class Data:
        def __init__(self, grow_count: int, aging_count: int,
                     show_count: int) -> None:
            self._grow_count = grow_count
            self._aging_count = aging_count
            self._show_count = show_count

        def add_grow(self) -> None:
            self._grow_count += 1

        def add_aging(self) -> None:
            self._aging_count += 1

        def add_show(self) -> None:
            self._show_count += 1

        def get_grow_count(self) -> int:
            return self._grow_count

        def get_aging_count(self) -> int:
            return self._aging_count

        def get_show_count(self) -> int:
            return self._show_count

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
        self._data = Plant.Data(0, 0, 0)

    @classmethod
    def init_partial(cls, height: float,
                     age: int, growth_per_day: float) -> "Plant":
        return cls("Anonymous", height, age, growth_per_day)

    def show_extra(self) -> str:
        return ""

    def show(self) -> None:
        print(self._name, ": ", self._height,
              "cm, ", self._age, " days old, ", self._growth_per_day,
              " growth rate", self.show_extra(), sep="")
        self.get_data().add_show()

    def aging(self) -> None:
        self.set_age(self._age + 1)
        self.get_data().add_aging()

    def grow(self) -> None:
        self.set_height(round(self._height + self._growth_per_day, 2))
        self.get_data().add_grow()

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

    def get_name(self) -> str:
        return self._name

    def get_data(self) -> Data:
        return self._data

    @staticmethod
    def check_age(age) -> None:
        if (age > 365):
            print("Is " + str(age) + " days more than a year? -> True")
        else:
            print("Is " + str(age) + " days more than a year? -> False")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, color: str, is_bloom: str) -> None:
        super().__init__(name, height, age, growth_per_day)
        self._color = color
        self._is_bloom = self._name + is_bloom

    def bloom(self) -> None:
        self._is_bloom = self._name + " is blooming beautifully!"

    def show_extra(self) -> str:
        return self._color + " color, " + self._is_bloom


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, trunk_diameter: float) -> None:
        super().__init__(name, height, age, growth_per_day)
        self._trunk_diameter = trunk_diameter
        self._shade_count = 0

    def produce_shade(self) -> None:
        print("Tree", self._name, "now produces a shade of", self._height,
              "cm long and", self._trunk_diameter, "cm wide.")
        self._shade_count += 1

    def get_shade_count(self) -> int:
        return self._shade_count

    def show_extra(self) -> str:
        return ", " + str(self._trunk_diameter) + " trunk diameter"


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, harvest_season: str,
                 nutritional_value: int) -> None:
        super().__init__(name, height, age, growth_per_day)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show_extra(self) -> str:
        return (", harvest season: " + self._harvest_season +
                ", nutritional value: " + str(self._nutritional_value))

    def grow(self) -> None:
        super().grow()
        self._nutritional_value += 1

    def aging(self) -> None:
        super().aging()
        self._nutritional_value += 1


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int,
                 growth_per_day: float, color: str, is_bloom: str,
                 seeds: int) -> None:
        super().__init__(name, height, age, growth_per_day, color, is_bloom)
        self._seeds = seeds

    def show_extra(self):
        return super().show_extra() + ", " + str(self._seeds) + " seeds"

    def bloom(self):
        super().bloom()
        self._seeds = 42


def show_stats(plant: Plant) -> None:
    print("Stats:", plant.get_data().get_grow_count(),
          "grow,", plant.get_data().get_aging_count(),
          "aging,", plant.get_data().get_show_count(),
          "show", end="")
    if isinstance(plant, Tree):
        print(",", plant.get_shade_count(), "shade")
    else:
        print()


if __name__ == "__main__":

    print("=== Garden statistics ===\n")
    print("=== Check year-old")
    Plant.check_age(30)
    Plant.check_age(400)
    print("")

    print("=== Flower")
    rose: Flower = Flower("Rose", 15.0, 10, 3.3, "red", " has not bloomed yet")
    rose.show()
    print("[Statistics for Rose]")
    show_stats(rose)
    print("[Asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    print("[Statistics for Rose]")
    show_stats(rose)
    print("")

    print("=== Tree")
    oak: Tree = Tree("Oak", 150.0, 10, 3.3, 15.5)
    oak.show()
    print("[Statistics for Oak]")
    show_stats(oak)
    print("[Asking the oak to produce shade]")
    oak.produce_shade()
    print("[Statistics for Oak]")
    show_stats(oak)
    print("")

    print("=== Seed")
    sunflower: Seed = Seed("Sunflower", 12.0, 7, 0.4,
                           "yellow", " has not bloomed yet", 0)
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.aging()
    sunflower.bloom()
    sunflower.show()
    print("[Statistics for Sunflower]")
    show_stats(sunflower)
    print("")

    print("=== Anonymous")
    anon: Plant = Plant.init_partial(1.0, 1, 1.0)
    anon.show()
    print("[statistics for Unknown plant]")
    show_stats(anon)
