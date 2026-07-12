#include <unistd.h>

void ft_putnbr_hex(int nbr)
{
	char *digits = "0123456789abcdef";
	char letter;
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16);
	if (nbr % 16 > 9)
	{
		letter = digits[nbr % 16];
		write(1, &letter, 1);
	}
	else
	{
		nbr = nbr % 16 + '0';
		write(1, &nbr, 1);
	}
}

int ft_atoi(char *nbr)
{
	int res = 0;
	while (*nbr)
	{
		res = res * 10 + *nbr - '0';
		nbr++;
	}
	return (res);
	
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		int nbr = ft_atoi(argv[1]);
		ft_putnbr_hex(nbr);
		write(1, "\n", 1);
	}
}