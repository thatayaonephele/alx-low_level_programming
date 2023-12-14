#include "main.h"
#include <stdlib.h>
/**
 * get_bit - returns the value of a bit at a given index.
 * @n: checks the bits
 * @index: Position placer that checks bit
 * Return: the value of the bit at index index
 * Or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index <= 64)
		return ((n >> index) & 1);
	else
		return (-1);
}
