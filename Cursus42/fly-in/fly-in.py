from map_parser import parse
import sys


def main() -> None:
    file_name: str = sys.argv[1]
    try:
        with open(file_name, 'r') as map_file:
            content: str = map_file.read()
    except OSError as e:
        print(f"Error while attempting to read '{file_name}' file: {e}",
              file=sys.stderr)
        sys.exit(1)

    validated: bool = parse(content)
    print(validated)


if __name__ == "__main__":
    main()
