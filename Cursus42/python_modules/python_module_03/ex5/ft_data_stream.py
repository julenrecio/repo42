#!/usr/bin/env python3

import typing
import random

players: list = ['alice', 'bob', 'charlie', 'dylan']
actions: list = ['run', 'eat', 'sleep', 'grab', 'move',
                 'climb', 'swim', 'release']


def gen_event() -> typing.Generator[tuple, None, None]:
    player: str = players[random.randint(0, len(players) - 1)]
    action: str = actions[random.randint(0, len(actions) - 1)]
    pair: tuple = (player, action)
    yield pair


def gen_list() -> list:
    list_ten: list = []
    for _ in range(10):
        pair: tuple = next(gen_event())
        list_ten.append(pair)
    return list_ten


def consume_event(left_events: list) -> typing.Generator[list, None, None]:
    while left_events:
        event: int = random.randint(0, len(left_events) - 1)
        print("Got event from list:", left_events[event])
        left_events.remove(left_events[event])
        yield left_events


def displpay_loop() -> None:
    for i in range(1000):
        pair: tuple = next(gen_event())
        print("Event {}: Player {} did action {}".
              format(i, pair[0], pair[1]))


def remove_loop(list_ten: list) -> None:
    for left in consume_event(list_ten):
        print("Remains in list:", left)


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    displpay_loop()
    list_ten: list = gen_list()
    print("Built list of 10 events:", list_ten)
    remove_loop(list_ten)
