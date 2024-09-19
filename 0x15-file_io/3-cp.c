#include "main.h"

/**
 * byte_buff - Allocates 1024 bytes for a buffer.
 * @my_f: The name of the file for which the buffer is storing characters.
 *
 * Return: A pointer to the newly-allocated memory buffer.
 */
char *byte_buff(char *my_f)
{
	char *my_buf;

	my_buf = malloc(sizeof(char) * 1024);

	if (!my_buf)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", my_f);
		exit(99);
	}

	return (my_buf);
}

/**
 * w_q_vi_file - Closes the specified file descriptor.
 * @file_des: The file descriptor to be closed.
 *
 * Return: Void
 */
void w_q_vi_file(int file_des)
{
	int chr;

	chr = close(file_des);
	if (chr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_des);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of command-line arguments supplied to the program.
 * @argv: An array of pointers to the arguments (source file and dest file)
 *
 * Return: 0 on success, otherwise exits with error codes.
 */
int main(int argc, char *argv[])
{
	int dest, write_d;
	char *my_buf;
	int read_d, src;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	my_buf = byte_buff(argv[2]);
	src = open(argv[1], O_RDONLY);
	read_d = read(src, my_buf, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	for (; read_d > 0; )
	{
		if (src == -1 || read_d == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(my_buf);
			exit(98);
		}
		write_d = write(dest, my_buf, read_d);
		if (dest == -1 || write_d == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(my_buf);
			exit(99);
		}
		read_d = read(src, my_buf, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
	}
	free(my_buf);
	w_q_vi_file(src);
	w_q_vi_file(dest);
	return (0);
}
