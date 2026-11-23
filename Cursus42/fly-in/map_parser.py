""" from models import Zone, Connection, Map, Metadata

def parse_map(content: list[str]) -> Map:
    nb_drones: int = 0
    for line in content:
        if line.startswith('#') or line.strip() == '':
            continue
        elif line.startswith("nb_drones: "):
 """