from typing import Any
from models import Map, ZoneRole, Zone, Connection
from pydantic import ValidationError


class MapParseError(Exception):
    pass


def extract_metadata(body: str, line_num: int,
                     allowed_metadata: set[str]) -> dict[str, Any]:

    if '[' not in body and ']' not in body:
        return {}
    elif not body.endswith(']') or '[' not in body:
        raise MapParseError("Bad bracket format for metadata in line {}.".
                            format(line_num))

    _, _, metadata = body.partition('[')
    metadata = metadata[:-1].strip()

    if not metadata:
        raise MapParseError("Empty metadata in line {}.".format(line_num))

    for char in metadata:
        if char in ("_", "=", " ") or char.isalnum():
            continue
        else:
            raise MapParseError("Invalid character in metadata in line {}.".
                                format(line_num))

    metadata_dict: dict[str, Any] = {}
    for pair in metadata.split():
        if "=" not in pair:
            raise MapParseError("Bad format for metadata entry in line {}.".
                                format(line_num))
        key, value = pair.split("=", 1)
        if not key or not value:
            raise MapParseError("Key or value missing for metadata entry in "
                                "line {}".format(line_num))
        if key not in allowed_metadata:
            raise MapParseError("Invalid key in metadata in line {}."
                                .format(line_num))
        if key == "zone":
            key = "type"
        if key in metadata_dict:
            raise MapParseError("Duplicate key in metadata in line {}."
                                .format(line_num))
        metadata_dict[key] = value
    return metadata_dict


def parse_zone(role: ZoneRole, body: str, line_num: int) -> Zone:
    allowed_zone_metadata: set[str] = {"zone", "color", "max_drones"}
    metadata: dict[str, Any] = extract_metadata(body, line_num,
                                                allowed_zone_metadata)
    body = body.partition("[")[0].strip()
    attr_list: list[str] = body.split()
    if len(attr_list) != 3:
        raise MapParseError("Bad arguments for zone in line {}. "
                            "Expected '<name> <x> <y>'.".format(line_num))
    name: str = attr_list[0]

    try:
        x: int = int(attr_list[1])
        y: int = int(attr_list[2])
    except ValueError as e:
        raise MapParseError("Coordinates must be integers in line {}.".
                            format(line_num)) from e
    try:
        return Zone(name=name, x=x, y=y, role=role, **metadata)
    except ValidationError as e:
        msgs: str = ""
        for err in e.errors():
            msgs = msgs + err["msg"].removeprefix("Value error, ") + "\n"
        raise MapParseError(msgs.strip()) from e


def parse_connection(body: str, zones_by_name: dict[str, Zone],
                     line_num: int) -> Connection:
    allowed_conn_metadata: set[str] = {"max_link_capacity"}
    metadata: dict[str, Any] = extract_metadata(body, line_num,
                                                allowed_conn_metadata)
    body = body.partition("[")[0].strip()
    if '-' not in body:
        raise MapParseError("Bad format for connection definition in line {}."
                            .format(line_num))
    zone_a_name, zone_b_name = body.split('-', 1)
    zone_a_name = zone_a_name.strip()
    zone_b_name = zone_b_name.strip()
    if '-' in zone_a_name or '-' in zone_b_name:
        raise MapParseError("Zone names cannot have the character '-'")
    if (zone_a_name not in zones_by_name.keys() or
            zone_b_name not in zones_by_name.keys()):
        raise MapParseError("Not registered zone detected in line {}."
                            .format(line_num))
    try:
        return Connection(zone_from=zones_by_name[zone_a_name],
                          zone_to=zones_by_name[zone_b_name], **metadata)
    except ValidationError as e:
        msgs: str = ""
        for err in e.errors():
            msgs = msgs + err["msg"].removeprefix("Value error, ") + "\n"
        raise MapParseError(msgs.strip()) from e


def parse_map(content: list[str]) -> Map:
    zone_or_conn_defined: bool = False
    nb_drones: int | None = None
    zones_by_name: dict[str, Zone] = {}
    connection_lines: list[tuple[int, str]] = []
    connections: list[Connection] = []

    for line_num, line in enumerate(content, start=1):
        line = line.split('#', 1)[0].strip()

        if not line:
            continue

        if ':' not in line:
            raise MapParseError("Bad instruction format in line {}.".
                                format(line_num))
        prefix, body = line.split(':', 1)
        prefix, body = prefix.strip(), body.strip()

        if prefix == "nb_drones":
            if zone_or_conn_defined:
                raise MapParseError("A zone or a connection has already been "
                                    "defined, wrong 'nb_drones' instruction "
                                    "in line {}.".format(line_num))
            elif nb_drones is not None:
                raise MapParseError("Duplicated instruction for number of "
                                    "drones in line {}.".format(line_num))
            else:
                try:
                    nb_drones = int(body.strip())
                except ValueError as e:
                    raise MapParseError("Invalid drone number in line {}."
                                        "Must be a valid positive integer"
                                        .format(line_num)) from e

        elif prefix in [ZoneRole.START, ZoneRole.END, ZoneRole.HUB]:
            zone: Zone = parse_zone(ZoneRole(prefix), body, line_num)
            if zone.name in zones_by_name:
                raise MapParseError("Duplicate zone name '{}' in line {}"
                                    .format(zone.name, line_num))
            zones_by_name[zone.name] = zone
            zone_or_conn_defined = True

        elif prefix == "connection":
            connection_lines.append((line_num, body))
            zone_or_conn_defined = True

        else:
            raise MapParseError("Unknown instruction in line {}."
                                .format(line_num))

    for line_num, body in connection_lines:
        conn: Connection = parse_connection(body, zones_by_name, line_num)
        connections.append(conn)

    if nb_drones is None:
        raise MapParseError("Number of drones not defined in file")

    try:
        return Map(nb_drones=nb_drones, zones=list(zones_by_name.values()),
                   connections=connections)
    except ValidationError as e:
        msgs: str = ""
        for err in e.errors():
            msgs = msgs + err["msg"].removeprefix("Value error, ") + "\n"
        raise MapParseError(msgs.strip()) from e
