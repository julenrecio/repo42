from models import Map
from map_parser import parse_map
import sys


def main() -> None:
    file_name: str = sys.argv[1]
    try:
        with open(file_name, 'r') as map_file:
            content: list[str] = map_file.readlines()
    except OSError as e:
        print(f"Error while attempting to read '{file_name}' file: {e}",
              file=sys.stderr)
        sys.exit(1)

    map: Map = parse_map(content)
    print(map)


if __name__ == "__main__":
    main()
