from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed: list = dark_spell_allowed_ingredients()
    for ingridient in allowed:
        if ingridient in ingredients:
            return "(" + ingredients + " - VALID)"
    return "(" + ingredients + " - INVALID)"
