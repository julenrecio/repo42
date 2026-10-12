#!/usr/bin/env python3

from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from enum import Enum


class ContactType(str, Enum):
    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime = Field()
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType = Field()
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def custom_validation_rules(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")
        if (self.contact_type == ContactType.physical):
            if (self.is_verified is False):
                raise ValueError("Physical contact reports must be verified")
        if (self.contact_type == ContactType.telepathic):
            if (self.witness_count < 3):
                raise ValueError("Telepathic contact requires "
                                 "at least 3 witnesses")
        if self.signal_strength > 7.0 and self.message_received is None:
            raise ValueError("Strong signals (> 7.0) should "
                             "include received messages")
        return self


if __name__ == "__main__":
    ac001: AlienContact = AlienContact(contact_id="AC_2024_001",
                                       timestamp=datetime.now(),
                                       location="Area 51, Nevada",
                                       contact_type=ContactType.radio,
                                       signal_strength=8.5,
                                       witness_count=5,
                                       duration_minutes=45,
                                       message_received="'Greetings from "
                                       "Zeta Reticuli'")
    print("Alien Contact Log Validation")
    print("========================================")
    print("Valid contact report:")
    print("ID:", ac001.contact_id)
    print("Type:", ac001.contact_type.name)
    print("Location:", ac001.location)
    print("Signal: ", ac001.signal_strength, "/10", sep="")
    print("Duration:", ac001.duration_minutes, "minutes")
    print("Witnesses:", ac001.witness_count)
    print("Message:", ac001.message_received)
    print("\n========================================")
    print("Expected validation error:")

    try:
        ac002: AlienContact = AlienContact(contact_id="AC_2024_001",
                                           timestamp=datetime.now(),
                                           location="Area 51, Nevada",
                                           contact_type=ContactType.telepathic,
                                           signal_strength=8.5,
                                           witness_count=2,
                                           duration_minutes=45,
                                           message_received="Greetings from "
                                           "Zeta Reticuli")
    except ValidationError as e:
        error = e.errors()[0].get("ctx")
        if error:
            print(str(error["error"]))
