def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed_type = seed_type.capitalize()
    if (unit == "packets"):
        text = "{} seeds: {} packets available".format(seed_type, quantity)
    elif (unit == "grams"):
        text = "{} seeds: {} grams total".format(seed_type, quantity)
    elif (unit == "area"):
        text = "{} seeds: covers {} square meters".format(seed_type, quantity)
    else:
        text = "Unkown unit type"
    print(text)
