#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *str;
	char *old;
	char *new;

	if (argc != 4)
	{
		write(1, "\n", 1);		
		exit(0);
	}
	else
	{
		str = argv[1];
		old = argv[2];
		new = argv[3];
		if (*(old + 1) != '\0' || *(new + 1) != '\0')
		{
			write(1, "\n", 1);
			exit(0);
		}
		else
		{
			while (*str)
			{
				if (*str == *old)
					write(1, new, 1);
				else
					write(1, str, 1);
				str++;
			}
			write(1, "\n", 1);
			exit(0);
		}
	}
}