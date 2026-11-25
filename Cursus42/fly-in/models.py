from enum import StrEnum
from pydantic import BaseModel, Field, model_validator


class ZoneRole(StrEnum):
    START = "start_hub"
    HUB = "hub"
    END = "end_hub"


class ZoneType(StrEnum):
    NORMAL = "normal"
    BLOCK = "blocked"
    RESTRICT = "restricted"
    PRIORITY = "priority"


class Zone(BaseModel):
    name: str = Field(min_length=1)
    x: int
    y: int
    role: ZoneRole
    type: ZoneType = Field(default=ZoneType.NORMAL)
    color: str | None = None
    max_drones: int = Field(default=1, ge=1)


class Connection(BaseModel):
    zone_from: Zone
    zone_to: Zone
    max_link_capacity: int = Field(default=1, ge=1)

    @model_validator(mode='after')
    def check_valid_connection(self) -> "Connection":
        if self.zone_from.name == self.zone_to.name:
            raise ValueError("A valid connection must involve two "
                             "different zones")
        return self


class Map(BaseModel):
    nb_drones: int = Field(gt=0)
    zones: list[Zone] = Field(min_length=2)
    connections: list[Connection] = Field(default_factory=list[Connection],
                                          min_length=1)

    @model_validator(mode='after')
    def check_name_and_coords_unique(self) -> "Map":
        unique_zone_names: set[str] = set()
        unique_zone_coords: set[tuple[int, int]] = set()
        for zone in self.zones:
            if zone.name in unique_zone_names:
                raise ValueError("Every zone name must be unique")
            if (zone.x, zone.y) in unique_zone_coords:
                raise ValueError("The coordinates of every zone must be "
                                 "unique")
            unique_zone_names.add(zone.name)
            unique_zone_coords.add((zone.x, zone.y))
        return self

    @model_validator(mode='after')
    def check_start_end_hubs(self) -> "Map":
        start_hubs: int = 0
        end_hubs: int = 0
        for zone in self.zones:
            if zone.role == ZoneRole.START:
                start_hubs += 1
            if zone.role == ZoneRole.END:
                end_hubs += 1
        if start_hubs != 1 or end_hubs != 1:
            raise ValueError("There must be exactly one start_hub and "
                             "one end_hub")
        return self

    @model_validator(mode='after')
    def check_duplicate_connections(self) -> "Map":
        unique_connections: set[tuple[str, str]] = set()
        for conn in self.connections:
            a, b = sorted((conn.zone_from.name, conn.zone_to.name))
            pair = (a, b)
            if pair in unique_connections:
                raise ValueError("There must not be duplicate connections "
                                 "(a-b and b-a are the same connection)")
            unique_connections.add(pair)
        return self
