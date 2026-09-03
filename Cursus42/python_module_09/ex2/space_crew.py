#!/usr/bin/env python3

from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from enum import Enum


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank = Field()
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime = Field()
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def custom_validation_rules(self) -> "SpaceMission":
        proper_rank: bool = False
        exp_members: int = 0
        all_active: bool = True
        for member in self.crew:
            if (member.rank == Rank.captain or member.rank == Rank.commander):
                proper_rank = True
            if (member.years_experience >= 5):
                exp_members += 1
            if (not member.is_active):
                all_active = False
        if not self.mission_id.startswith("M"):
            raise ValueError("Contact ID must start with 'AC'")
        if (not proper_rank):
            raise ValueError("Mission must have at least "
                             "one Commander or Captain")
        if (self.duration_days > 365 and (len(self.crew) / 2) > exp_members):
            raise ValueError("Long missions (> 365 days) need 50%"
                             " experienced crew (5+ years)")
        if (not all_active):
            raise ValueError("All crew members must be active")
        return self


if __name__ == "__main__":
    cm001: CrewMember = CrewMember(member_id="cm001",
                                   name="Sarah Connor",
                                   rank=Rank.commander,
                                   age=31,
                                   specialization="Mission Command",
                                   years_experience=6,
                                   is_active=True)
    cm002: CrewMember = CrewMember(member_id="cm002",
                                   name="John Smith",
                                   rank=Rank.lieutenant,
                                   age=37,
                                   specialization="Navigation",
                                   years_experience=10,
                                   is_active=True)
    cm003: CrewMember = CrewMember(member_id="cm003",
                                   name="Alice Johnson",
                                   rank=Rank.officer,
                                   age=24,
                                   specialization="Engineering",
                                   years_experience=3,
                                   is_active=True)
    sm001: SpaceMission = SpaceMission(mission_id="M2024_MARS",
                                       mission_name="Mars Colony "
                                                    "Establishment",
                                       destination="Mars",
                                       launch_date=datetime.now(),
                                       duration_days=900,
                                       crew=[cm001, cm002, cm003],
                                       budget_millions=2500.0)
    print("Space Mission Crew Validation")
    print("========================================")
    print("Valid mission created:")
    print("Name:", sm001.mission_name)
    print("ID:", sm001.mission_id)
    print("Destination:", sm001.destination)
    print("Duration:", sm001.duration_days, "days")
    print("Budget: $", sm001.budget_millions, "M", sep="")
    print("Crew size:", len(sm001.crew))
    print("Crew members:")
    for member in sm001.crew:
        print("- {} ({}) - {}".
              format(member.name, member.rank.name, member.specialization))
    print("\n========================================")
    print("Expected validation error:")

    try:
        cm001.rank = Rank.cadet
        sm002: SpaceMission = SpaceMission(mission_id="M2024_MARS",
                                           mission_name="Mars Colony "
                                                        "Establishment",
                                           destination="Mars",
                                           launch_date=datetime.now(),
                                           duration_days=900,
                                           crew=[cm001, cm002, cm003],
                                           budget_millions=2500.0)
    except ValidationError as e:
        error = e.errors()[0].get("ctx")
        if error:
            print(str(error["error"]))
