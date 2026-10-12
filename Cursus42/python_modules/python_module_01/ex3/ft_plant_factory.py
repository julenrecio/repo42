#!/opt/pyenv/shims/python3

class Plant:

    def __init__(self, name, height, age, growth_per_day):
        self.name = name
        self.height = height
        self.age = age
        self.growth_per_day = growth_per_day

    def show(self):
        print("Created: ", self.name, ": ", self.height,
              "cm, ", self.age, " days old", sep="")

    def grow(self):
        self.height = round(self.height + self.growth_per_day, 2)

    def aging(self):
        self.age = self.age + 1


if __name__ == "__main__":

    print("=== Plant Factory Output ===")

    plant1 = Plant("Rose", 25.0, 30, 0.8)
    plant2 = Plant("Oak", 200.0, 365, 1.2)
    plant3 = Plant("Cactus", 5.0, 90, 0.1)
    plant4 = Plant("Sunflower", 80.0, 45, 0.4)
    plant5 = Plant("Fern", 15.0, 120, 0.7)

    plant1.show()
    plant2.show()
    plant3.show()
    plant4.show()
    plant5.show()
