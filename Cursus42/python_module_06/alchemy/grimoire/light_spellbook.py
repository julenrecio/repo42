import alchemy.grimoire


def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    result: str = alchemy.grimoire.validate_ingredients(ingredients)
    if ("VALID" in result):
        return "Spell recorded: " + spell_name + " " + result
    else:
        return "Spell rejected: " + spell_name + " " + result
