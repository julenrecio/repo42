def ft_count_harvest_recursive() -> None:
    days = int(input("Days until harvest: "))
    ft_print_day(1, days)
    print("Harvest time!")


def ft_print_day(day: int, days: int) -> None:
    print("Day", day)
    if (day < days):
        ft_print_day(day + 1, days)
