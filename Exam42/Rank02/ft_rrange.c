#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	num_values;
	int ascendent;
	int *res;
	int i;

	if (start > end)
	{
		num_values = start - end;
		ascendent = 1;
	}
	else
	{
		num_values = end - start;
		ascendent = 0;
	}
	num_values++;

	res = malloc(sizeof(int)*num_values);
	i = 0;
	if (ascendent)
	{
		while (i <= start - end)
		{
			*res = end + i;
			res++;
			i++;
		}	
	}
	else
	{
		while (i <= end - start)
		{
			*res = end - i;
			res++;
			i++;
		}
	}
	res -= num_values;
	return (res);
}

#include <stdio.h>
int main()
{
	int start = -42;
	int end = 42;
	int *range = ft_rrange(start, end);
	while (*range != start)
	{
		printf("%d, ", *range);
		range++;
	}
	printf("%d\n", *range);
}