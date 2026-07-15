int	is_power_of_2(unsigned int n)
{
	while (n > 1 && n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	else
		return (0);
}