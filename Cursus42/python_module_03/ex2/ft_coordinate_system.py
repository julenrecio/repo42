#!/usr/bin/env python3

import math


def get_player_pos() -> tuple:
    while (True):
        try:
            input_coords: list = input("Enter new coordinates "
                                       "as floats in format "
                                       "'x,y,z': ").split(", ")
            if (len(input_coords) != 3):
                raise ValueError("Invalid syntax")
            output_coords: list = []
            for coord in input_coords:
                try:
                    output_coords.append(float(coord))
                except ValueError as e:
                    raise ValueError(("Error on parameter '{}': {}").
                                     format(coord, e)) from e
            return tuple(output_coords)
        except ValueError as e:
            print(e)


def distance(point1: tuple, point2: tuple) -> float:
    return round(math.sqrt(((point2[0]-point1[0])**2 +
                            (point2[1]-point1[1])**2 +
                            (point2[2]-point1[2])**2)), 4)


if __name__ == "__main__":
    print("Get a first set of coordinates")
    coords1: tuple = get_player_pos()
    print("Got a first tuple:", coords1)
    print("It includes: X=", coords1[0], ", Y=",
          coords1[1], ", Z=", coords1[2], sep="")
    print("Distance to center:", distance(coords1, (0, 0, 0)))
    print("Get a second set of coordinates")
    coords2: tuple = get_player_pos()
    print("Distance between the 2 sets of coordinates:",
          distance(coords1, coords2))
