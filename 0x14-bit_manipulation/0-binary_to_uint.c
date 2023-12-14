#include "main.h"

/**
* binary_to_uint - Converts a binary to an unsigned int
* @b: The binary number of the string
* Return:The unsigned int as a converted value
*/
unsigned int binary_to_uint(const char *b)
{
	int x = 0;
	unsigned int my_num = 0;

	if (b[x] != '\0')
	{
	while ((b[x] == '1') || (b[x] == '0'))
	{
		my_num <<= 1;
		my_num = my_num + b[x] - '0';
		x++;
	}
	return (my_num);
	}
	else
		return (0);
}
