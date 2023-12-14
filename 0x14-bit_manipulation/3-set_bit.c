#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: A pointer to the bit number
 * @index: The index to set the value at the position to be changed
 * Return: 1 if successful else -1 on error.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	int unsigned_long_int_size;

	unsigned_long_int_size  = sizeof(unsigned long int);
	*n = *n | (1 << index);
	if (index >= (unsigned_long_int_size * unsigned_long_int_size))
		return (-1);
	else
		return (1);
}
