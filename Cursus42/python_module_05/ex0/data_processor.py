#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):

    def __init__(self) -> None:
        self._data: list[str] = []
        self._next_rank: int = 0

    def get_data(self) -> Any:
        return self._data

    def get_rank(self) -> int:
        return self._next_rank

    def set_rank(self, rank: int) -> None:
        self._next_rank = rank

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        return self.get_data().pop(0)

    def process_data(self, data: Any) -> None:
        if (self.validate(data)):
            self.ingest(data)


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            for number in data:
                if not isinstance(number, (int, float)):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise TypeError("Improper numeric data")
        if not isinstance(data, list):
            data = [data]
        for value in data:
            self.get_data().append((self.get_rank(), str(value)))
            self.set_rank(self.get_rank() + 1)


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            for string in data:
                if not isinstance(string, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise TypeError("Improper text data")
        if not isinstance(data, list):
            data = [data]
        for value in data:
            self.get_data().append((self.get_rank(), value))
            self.set_rank(self.get_rank() + 1)


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if (isinstance(data, dict)):
            for k, v in data.items():
                if not (isinstance(k, str) and isinstance(v, str)):
                    return False
            return True
        elif ((isinstance(data, list)) and
              all(isinstance(x, dict) for x in data)):
            for strdict in data:
                for k, v in strdict.items():
                    if not (isinstance(k, str) and isinstance(v, str)):
                        return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise TypeError("Improper log data")
        if not isinstance(data, list):
            data = [data]
        for value in data:
            self.get_data().append((self.get_rank(),
                                   "{}: {}".format(list(value.values())[0],
                                                   list(value.values())[1])))
            self.set_rank(self.get_rank() + 1)


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print("\nTesting Numeric Processor...")
    num_proc: NumericProcessor = NumericProcessor()
    print(" Trying to validate input '42': {}".format(num_proc.validate(42)))
    print(" Trying to validate input 'Hello': {}"
          .format(num_proc.validate("hello")))
    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_proc.ingest("foo")
    except Exception as e:
        print(" Got exception:", e)
    num_data: list = [1, 2, 3, 4, 5]
    print(" Processing data: {}".format(num_data))
    num_proc.process_data(num_data)
    print(" Extracting 3 values...")
    for i in range(3):
        num_extract: tuple[int, str] = num_proc.output()
        print(" Numeric value {}: {}".format(num_extract[0], num_extract[1]))

    print("\nTesting Text Processor...")
    text_proc: TextProcessor = TextProcessor()
    print(" Trying to validate input '42': {}".format(text_proc.validate(42)))
    text_data: list[str] = ["Hello", "Nexus", "World"]
    print(" Processing data: {}".format(text_data))
    text_proc.process_data(text_data)
    print(" Extracting 1 value...")
    text_extract: tuple[int, str] = text_proc.output()
    print(" Text value {}: {}".format(text_extract[0], text_extract[1]))

    print("\nTesting Log Processor...")
    log_proc: LogProcessor = LogProcessor()
    print(" Trying to validate input 'Hello': {}".
          format(log_proc.validate("Hello")))
    log_data: list[dict[str, str]] = [{'log_level': 'NOTICE',
                                       'log_message': 'Connection to server'},
                                      {'log_level': 'ERROR',
                                       'log_message': 'Unauthorized access!!'}]
    print(" Processing data: {}".format(log_data))
    log_proc.process_data(log_data)
    print(" Extracting 2 values...")
    for i in range(2):
        log_extract: tuple[int, str] = log_proc.output()
        print(" Log entry {}: {}".format(log_extract[0], log_extract[1]))
