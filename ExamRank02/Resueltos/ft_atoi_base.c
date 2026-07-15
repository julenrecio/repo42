int	ft_atoi_base(const char *str, int str_base)
{
	int neg = 0;
	int nb = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * str_base + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			nb = nb * str_base + (*str - 87);
		else if (*str >= 'A' && *str <= 'F')
			nb = nb * str_base + (*str - 55);
		else
			break;
		str++;
	}
	if (neg)
		nb = -nb;
	return (nb);
}

//#include <stdio.h>
/* int main()
{
	printf("%d\n", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.", 16));
} */