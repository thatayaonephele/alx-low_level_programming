#include "main.h"

/**
 * get_endianness - Checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *ch = (char *)&x;

	if (!*ch)
		return (0);
	else
		return (1);
}
