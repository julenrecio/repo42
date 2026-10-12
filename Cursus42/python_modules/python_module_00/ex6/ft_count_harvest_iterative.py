def ft_count_harvest_iterative() -> None:
    days = int(input("Days until harvest: "))
    days_range = range(1, days + 1)
    i = 1
    while (i in days_range):
        print("Day", i)
        i += 1
    print("Harvest time!")
