#!/opt/pyenv/shims/python3

class Plant:

    def __init__(self, name: str, height: float, age: int) -> None:
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
        print("Plant created: ", end="")
        self.show()

    def show(self) -> None:
        print(self._name, ": ", self._height,
              "cm, ", self._age, " days old", sep="")

    def aging(self) -> None:
        self.set_age(self._age + 1)

    def set_height(self, height: float) -> None:
        if (height > 0.0):
            self._height = height
            print(self._name, ": Height updated: ", self._height, "cm", sep="")
        else:
            print(self._name, ": Update error, height can't be negative, "
                  "height update rejected", sep="")

    def set_age(self, age: int) -> None:
        if (age > 0):
            self._age = age
            print(self._name, ": Age updated: ", self._age, " days", sep="")
        else:
            print(self._name, ": Update error, age can't be negative, "
                  "age update rejected", sep="")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age


if __name__ == "__main__":

    print("=== Garden Security System ===")

    plant: Plant = Plant("Rose", -25.0, -30)

    plant.set_age(-30)
    plant.set_age(30)
    plant.set_height(24.0)

    print("Current state: ", end="")
    plant.show()
