#!/opt/pyenv/shims/python3

class Plant:
    name: str
    cm: float
    age: int
    growth_per_day: float

    def show(self):
        print(self.name, ": ", self.cm, "cm, ", self.age, " days old", sep="")

    def grow(self):
        self.cm = round(self.cm + self.growth_per_day, 2)

    def aging(self):
        self.age = self.age + 1


if __name__ == "__main__":

    print("=== Garden Plant Growth ===")

    plant = Plant()

    plant.name = "Rose"
    plant.cm = 25.0
    plant.age = 30
    plant.growth_per_day = 0.8

    i = 1
    plant.show()
    for index in range(plant.age, plant.age + 7):
        print("=== Day", i, "===")
        plant.grow()
        plant.aging()
        plant.show()
        i += 1

    print("Growth this week: ", round(plant.growth_per_day*7, 2), "cm", sep="")
