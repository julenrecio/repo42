from map_parser import parse_map, MapParseError
from models import Map
import sys


def main() -> None:
    file_name: str = sys.argv[1]
    try:
        with open(file_name, 'r') as map_file:
            content: list[str] = map_file.readlines()
        map: Map = parse_map(content)
    except OSError as e:
        sys.exit("Error while attempting to read '{}' file: {}"
                 .format(file_name, e))
    except MapParseError as e:
        sys.exit("Map parse error:\n{}".format(e))

    print("Map loaded:\n", map)


if __name__ == "__main__":
    main()
