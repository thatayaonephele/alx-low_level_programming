#include "main.h"
/**
 * flip_bits - Flips bits to get from one number to another.
 * @n: The 1st number
 * @m: The 2nd number
 * Return: Number of bits needed to flip to get from 1 number to another
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int current_num;
	int x = 63, my_count = 0;
	unsigned long int difference_in_bit = n ^ m;

	while (x >= 0)
	{
		current_num = difference_in_bit >> x;
		if (1 & current_num)
			my_count++;
		x--;
	}
	return (my_count);
}
