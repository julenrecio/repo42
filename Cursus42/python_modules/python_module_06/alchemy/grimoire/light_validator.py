import alchemy.grimoire


def validate_ingredients(ingredients: str) -> str:
    allowed: list = alchemy.grimoire.light_spell_allowed_ingredients()
    current_ingredients: list = ingredients.replace(" and ", ",").split(",")
    for ingridient in current_ingredients:
        if ingridient.strip() in allowed:
            return "(" + ingredients + " - VALID)"
    return "(" + ingredients + " - INVALID)"
