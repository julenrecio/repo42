from typing import Any
from pydantic import BaseModel, Field, model_validator


class Metadata(BaseModel):
    key: str = Field(min_length=1)
    value: Any


class Zone(BaseModel):
    name: str = Field(min_length=1)
    x: int = Field(ge=0)
    y: int = Field(ge=0)
    metadata: list[Metadata] = Field(default_factory=list[Metadata])


class Connection(BaseModel):
    zone_from: Zone
    zone_to: Zone
    metadata: list[Metadata] = Field(default_factory=list[Metadata])

    @model_validator(mode='after')
    def check_valid_connection(self) -> "Connection":
        if self.zone_from == self.zone_to:
            raise ValueError("A valid connection must involve two "
                             "different zones")
        return self


class Map(BaseModel):
    zones: list[Zone] = Field(min_length=2)
    connections: list[Connection] = Field(default_factory=list[Connection],
                                          min_length=1)

    @model_validator(mode='after')
    def check_name_unique(self) -> "Map":
        unique_zone_names: set[str] = set()
        for zone in self.zones:
            if zone.name in unique_zone_names:
                raise ValueError("Every zone name must be unique")
            unique_zone_names.add(zone.name)
        return self
