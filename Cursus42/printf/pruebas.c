#include <stdio.h>

int	main(void)
{
	printf("%3$d, %1$d, %2$d", 2, 5, 1);
	printf("\n");
	printf("%03d", 1);
	printf("\n");
	printf("%03d", 100);
	printf("\n");
	printf("%#f", 3.14);
	printf("\n");
	printf("%#f", 42.42);
	printf("\n");
	printf("%*d, %*d", 0, 10, 10, 5);
	printf("\n");
	printf("%.*s", 3, "abcdef");
	printf("\n");
	printf("%.*f", 3, 42.4242);
	printf("\n");
	printf("%.3s", "abcdef");
	printf("\n");
	printf("%.3f", 42.4242);
	printf("\n");
	printf("%.4f", 42.4242);
	printf("\n");
	printf("%hhd", 'a');
	printf("\n");
	printf("%u", -10);
	printf("\n");
	printf("%o", 10);
	printf("\n");
	printf("%%");
	printf("\n");
}