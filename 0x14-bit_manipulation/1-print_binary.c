#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int to be printed in binary
 *
 * Return: Always Success (0)
 */
void print_binary(unsigned long int n)
{
	unsigned long int x;

	x = n >> 1;
	if (n > 1)
		print_binary(x); /*recursive right shift until n becomes <= 0)*/
	_putchar((n & 1) + '0');
}
