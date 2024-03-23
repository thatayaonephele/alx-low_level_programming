#include "lists.h"
/**
 *main- Entry point
 *@argc: The argument count parameter
 *@argv: The argument vector parameter
 *Return:a valid key for the username
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char *y;
	int x, z;
	char tmp[7];
	int my_length = strlen(argv[1]);

	y = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	z = 63 & (my_length ^ 59);
	tmp[0] = y[z];
	z = 0;
	x = 0;
	while (x < my_length)
	{
		z += argv[1][x];
		x++;
	}
	tmp[1] = y[63 & (z ^ 79)];
	z = 1; /*initialize temporary z  to 1*/
	x = 0;
	while (x < my_length)
	{
		z *= argv[1][x];
		x++;
	}
	tmp[2] = y[63 & (z ^ 85)];
	x = 0;
	z = 0;
	while (x < my_length)
	{
		if (argv[1][x] > z)
			z = argv[1][x];
		x++;
	}
	srand(z ^ 14);
	tmp[3] = y[63 & rand()];
	x = 0;
	z = 0;
	while (x < my_length)
	{
		z += (argv[1][x] * argv[1][x]);
		x++;
	}
	tmp[4] = y[63 & (z ^ 239)];
	x = 0;
	while (x < argv[1][0])
	{
		z = rand();
		x++;
	}
	tmp[5] = y[63 & (z ^ 229)];
	tmp[6] = '\0'; /*set pos to null terminating char*/
	printf("%s", tmp); /*return the temp char*/
	return (0);
}
