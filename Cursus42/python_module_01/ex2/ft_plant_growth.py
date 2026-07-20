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

    plant1 = Plant()

    plant1.name = "Rose"
    plant1.cm = 25.0
    plant1.age = 30
    plant1.growth_per_day = 0.8

    i = 1
    plant1.show()
    for index in range(plant1.age, plant1.age + 7):
        print("=== Day", i, "===")
        plant1.grow()
        plant1.aging()
        plant1.show()
        i += 1
