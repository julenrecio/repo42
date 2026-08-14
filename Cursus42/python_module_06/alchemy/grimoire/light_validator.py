import light_spellbook

def validate_ingredients(ingredients: str):
    allowed: list = light_spellbook.light_spell_allowed_ingredients()
    for ingridient in allowed:
        if ingridient in ingredients:
            return "(" + ingredients + "- VALID)"
    return "(" + ingredients + "- INVALID)"