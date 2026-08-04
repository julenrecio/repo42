#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        pass
        #pop()

    def process_data(self, data: Any) -> None:
        if (self.validate(data)):
            self.ingest(data)


class NumericProcessor(DataProcessor):

    def __init__(self):
        self._data: list[str] = []

    def get_data(self) -> list[str]:
        return self._data

    def validate(self, data: Any) -> bool:
        if ((isinstance(data, (int, float)))
            or (isinstance(data, list)
                and all(isinstance(x, (int, float)) for x in data))):
            return True
        else:
            return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if (isinstance(data, (int, float))):
            self.get_data().append(str(data))
        elif (isinstance(data, list) and
              all(isinstance(x, (int, float)) for x in data)):
            for data_piece in data:
                self.get_data().append(str(data_piece))
        else:
            raise TypeError("Improper numeric data")


class TextProcessor(DataProcessor):

    def __init__(self):
        self._data: list[str] = []

    def get_data(self) -> list[str]:
        return self._data

    def validate(self, data: Any) -> bool:
        if ((isinstance(data, str))
            or (isinstance(data, list)
                and all(isinstance(x, str) for x in data))):
            return True
        else:
            return False

    def ingest(self, data: str | list[str]) -> None:
        try:
            self.get_data().append(data)
        except TypeError:
            print("Improper text data")


class LogProcessor(DataProcessor):

    def __init__(self):
        self._data: list[str] = []

    def get_data(self) -> list[str]:
        return self._data

    def validate(self, data: Any) -> bool:
        if ((isinstance(data, dict))
            or (isinstance(data, list)
                and all(isinstance(x, dict) for x in data))):
            return True
        else:
            return False

    def ingest(self, data: dict | list[dict]) -> None:
        try:
            self.get_data().append(data)
        except TypeError:
            print("Improper log data")


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print("\nTesting Numeric Processor...")

    num_proc: NumericProcessor = NumericProcessor()
    print("Trying to validate input '42': {}".format(num_proc.validate(42)))
    print("Trying to validate input 'Hello': {}".format(num_proc.validate("hello")))
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_proc.ingest("foo")
    except Exception as e:
        print(f"Got exception: {e}")
    num_data: list = [1, 2, 3, 4, 5]
    print("Processing data: {}".format(num_data))
    num_proc.process_data(num_data)

