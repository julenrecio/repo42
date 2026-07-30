#!/usr/bin/env python3

import sys


def operate_dict() -> None:
    print("=== Inventory System Analysis ===")
    elements: dict = {}
    for i in sys.argv[1:]:
        pair: list = i.split(":")
        if (len(pair) == 1):
            print(("Error - invalid parameter '{}'").format(pair[0]))
        elif (pair[0] in elements.keys()):
            print(("Redundant item '{}' - discarding").format(pair[0]))
        else:
            try:
                key: str = pair[0]
                value: int = int(pair[1])
                elements[key] = value
            except ValueError as e:
                print("Quantity error for '{}':".format(key), e)
    print("Got inventory:", elements)
    print("Item list:", list(elements.keys()))
    print("Total quantity of the {} items: {}".
          format(len(elements.keys()), sum(elements.values())))
    if (elements):
        max_key: str = list(elements.keys())[0]
        min_key: str = list(elements.keys())[0]
        for element in elements.keys():
            print("Item {} represents {}%".format
                  (element, round((int(elements[element]) /
                                   sum(elements.values()) * 100), 1)))
            if (elements[element] > elements[max_key]):
                max_key = element
            if (elements[element] < elements[min_key]):
                min_key = element
        print("Item most abundant: {} with quantity {}".
              format(max_key, max(elements.values())))
        print("Item least abundant: {} with quantity {}".
              format(min_key, min(elements.values())))
    elements.update({"magic_item": 1})
    print("Updated inventory:", elements)


if __name__ == "__main__":
    operate_dict()
