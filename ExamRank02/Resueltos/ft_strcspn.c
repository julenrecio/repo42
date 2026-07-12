#include <stddef.h>

int ft_strlen(const char *str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t bytes = 0;
	int len = ft_strlen(reject);
	while (*s)
	{
		while (*reject)
		{
			if (*s == *reject)
				return (bytes);
			reject++;
		}
		reject -= len;
		bytes += sizeof(*s);
		s++;
	}
	return (bytes);
}

/*
#include <stdio.h>
int main()
{
	printf("Bytes: %ld\n", ft_strcspn("hola que tal estas hoy", "is"));
}
*/