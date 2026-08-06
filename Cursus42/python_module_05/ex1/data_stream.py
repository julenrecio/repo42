#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):

    def __init__(self) -> None:
        self._data: list[str] = []
        self._rank: int = 0

    def get_data(self) -> Any:
        return self._data

    def get_rank(self) -> int:
        return self._rank

    def set_rank(self, rank: int) -> None:
        self._rank = rank

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
                                   "{}: {}".format(value["log_level"],
                                                   value["log_message"])))
            self.set_rank(self.get_rank() + 1)


class DataStream:

    def __init__(self) -> None:
        self._processors: dict[str, DataProcessor] = {}

    def get_processors(self) -> dict[str, DataProcessor]:
        return self._processors

    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, NumericProcessor):
            self.get_processors()["Numeric"] = proc
            print("Registering Numeric Processor")
        elif isinstance(proc, TextProcessor):
            self.get_processors()["Text"] = proc
            print("Registering text processor")
        elif isinstance(proc, LogProcessor):
            self.get_processors()["Log"] = proc
            print("Registering log processor")

    def process_stream(self, stream: list[Any]) -> None:
        pass

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
        else:
            if self.get_processors().get("Numeric"):
                num_proc: DataProcessor = self.get_processors()["Numeric"]
            if self.get_processors().get("Text"):
                text_proc: DataProcessor = self.get_processors()["Text"]
            if self.get_processors().get("Log"):
                log_proc: DataProcessor = self.get_processors()["Log"]
            print("Numeric Processor: total {} items processed, "
                  "remaining {} on processor"
                  .format(num_proc.get_rank(), len(num_proc.get_data())))
            print("Text Processor: total {} items processed, "
                  "remaining {} on processor"
                  .format(text_proc.get_rank(), len(text_proc.get_data())))
            print("Log Processor: total {} items processed, "
                  "remaining {} on processor"
                  .format(log_proc.get_rank(), len(log_proc.get_data())))


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===")
    print("\nInitialize Data Stream...")
