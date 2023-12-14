#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Pointer pointing to the bit number
 * @index: Index to set new value,starting at indice 0.
 * Return: 1 if function works,else -1 for error occurrance
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int max_data_size;
	unsigned int x;

	max_data_size = (sizeof(unsigned long int) * 8);
	x = 1 << index;
	if (index < max_data_size)
	{
		*n &= ~(x);
		return (1);
	}
	else
		return (-1);
}
