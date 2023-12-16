#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	ssize_t x;
	ssize_t y;
	ssize_t z;

	if (filename == NULL)
		return (0);
	b = malloc(sizeof(char) * letters);
	if (b == NULL)
		return (0);
	x = open(filename, O_RDONLY);
	y = read(x, b, letters);
	z = write(STDOUT_FILENO, b, y);
	if (x == -1)
	{
		free(b);
		return (0);
	}
	if (z != y)
	{
		free(b);
		return (0);
	}
	if (x == -1)
	{
		free(b);
		return (0);
	}
	if (z == -1)
	{
		free(b);
		return (0);
	}
	free(b);
	close(x);
	return (z);
}
