#include <unistd.h>

void ft_putnbr(int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

int main()
{
	int num = 1;
	while (num <= 100)
	{
		if (num % 3 == 0 && num % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (num % 3 == 0)
			write(1, "fizz\n", 5);
		else if (num % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(num);
			write(1, "\n", 1);
		}
		num++;
	}
	return (0);
}