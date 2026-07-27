#!/usr/bin/env python3

import sys


def list_to_int(scores: list) -> list:
    i: int = 0
    int_scores: list = []
    while (i < len(scores)):
        try:
            int_scores.append(int(scores[i]))
        except ValueError:
            print("Invalid parameter: " + "'" + scores[i] + "'")
        i += 1
    return int_scores


if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    scores: list = list_to_int(sys.argv[1:])
    num_players: int = len(scores)
    if (num_players == 0):
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score2> ...")
    else:
        print("Scores processed:", scores)
        print("Total players: {}".format(num_players))
        print("Total score: {}".format(sum(scores)))
        print("Average score: {}".format(sum(scores) / num_players))
        print("High score: {}".format(max(scores)))
        print("Low score: {}".format(min(scores)))
        print("Score range: {}".format(max(scores) - min(scores)))
