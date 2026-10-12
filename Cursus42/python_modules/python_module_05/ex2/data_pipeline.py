#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any, Protocol


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


class ExportPlugin(Protocol):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class CSVPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:
        i: int = 0
        for element in data:
            if (i % 3 == 0):
                print("CSV Output:")
                print(element[1], end="")
            else:
                print(',' + element[1], end="")
            i += 1
        print()


class JSONPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:
        i: int = 0
        for element in data:
            if (i % 5 == 0):
                print("JSON Output:")
                print('{{"item_{}": "{}"}}'
                      .format(element[0], element[1]), end="")
            else:
                print(', {{"item_{}": "{}"}}'
                      .format(element[0], element[1]), end="")
            i += 1
        print()


class DataStream:

    def __init__(self) -> None:
        self._processors: dict[str, DataProcessor] = {}

    def get_processors(self) -> dict[str, DataProcessor]:
        return self._processors

    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, NumericProcessor):
            self.get_processors()["Numeric"] = proc
        elif isinstance(proc, TextProcessor):
            self.get_processors()["Text"] = proc
        elif isinstance(proc, LogProcessor):
            self.get_processors()["Log"] = proc

    def process_stream(self, stream: list[Any]) -> None:
        num_proc = self.get_processors().get("Numeric")
        text_proc = self.get_processors().get("Text")
        log_proc = self.get_processors().get("Log")
        for data_piece in stream:
            if num_proc and num_proc.validate(data_piece):
                num_proc.ingest(data_piece)
            elif text_proc and text_proc.validate(data_piece):
                text_proc.ingest(data_piece)
            elif log_proc and log_proc.validate(data_piece):
                log_proc.ingest(data_piece)
            else:
                print("DataStream error - Can't process element in stream: ",
                      data_piece)

    def print_processors_stats(self) -> None:
        print("\n== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data\n")
        else:
            if self.get_processors().get("Numeric"):
                num_proc: DataProcessor = self.get_processors()["Numeric"]
                print("Numeric Processor: total {} items processed, "
                      "remaining {} on processor"
                      .format(num_proc.get_rank(), len(num_proc.get_data())))
            if self.get_processors().get("Text"):
                text_proc: DataProcessor = self.get_processors()["Text"]
                print("Text Processor: total {} items processed, "
                      "remaining {} on processor"
                      .format(text_proc.get_rank(), len(text_proc.get_data())))
            if self.get_processors().get("Log"):
                log_proc: DataProcessor = self.get_processors()["Log"]
                print("Log Processor: total {} items processed, "
                      "remaining {} on processor"
                      .format(log_proc.get_rank(), len(log_proc.get_data())))

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self.get_processors().values():
            output_list: list = []
            for _ in range(nb):
                if (len(processor.get_data()) != 0):
                    output: tuple[int, str] = processor.output()
                    output_list.append(output)
            plugin.process_output(output_list)


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===")
    print("\nInitialize Data Stream...")
    stream: DataStream = DataStream()
    stream.print_processors_stats()
    print("Registering Processors\n")
    num_proc: NumericProcessor = NumericProcessor()
    text_proc: TextProcessor = TextProcessor()
    log_proc: LogProcessor = LogProcessor()
    stream.register_processor(num_proc)
    stream.register_processor(text_proc)
    stream.register_processor(log_proc)
    print("Send first batch of data on stream: "
          "['Hello world', [3.14, -1, 2.71], "
          "[{'log_level': 'WARNING', 'log_message': "
          "'Telnet access! Use ssh instead'}, "
          "{'log_level': 'INFO', 'log_message': 'User wil is connected'}], "
          "42, ['Hi', 'five']]")
    stream.process_stream(['Hello world', [3.14, -1, 2.71],
                           [{'log_level': 'WARNING', 'log_message':
                             'Telnet access! Use ssh instead'},
                            {'log_level': 'INFO', 'log_message':
                             'User wil is connected'}], 42, ['Hi', 'five']])
    stream.print_processors_stats()
    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv_plugin: CSVPlugin = CSVPlugin()
    stream.output_pipeline(3, csv_plugin)
    stream.print_processors_stats()
    print("\nSend another batch of data: [21, ['I love AI',"
          "'LLMs are wonderful', 'Stay healthy'], [{'log_level': 'ERROR',"
          "'log_message': '500 server crash'}, {'log_level': 'NOTICE',"
          "'log_message': 'Certificate expires in 10 days'}],"
          "[32, 42, 64, 84, 128, 168], 'World hello']")
    stream.process_stream([21, ['I love AI', 'LLMs are wonderful',
                                'Stay healthy'],
                           [{'log_level': 'ERROR',
                             'log_message': '500 server crash'},
                            {'log_level': 'NOTICE', 'log_message':
                             'Certificate expires in 10 days'}],
                           [32, 42, 64, 84, 128, 168], 'World hello'])
    stream.print_processors_stats()
    print("\nSend 5 processed data from each processor to a JSON plugin:")
    json_plugin: JSONPlugin = JSONPlugin()
    stream.output_pipeline(5, json_plugin)
    stream.print_processors_stats()
