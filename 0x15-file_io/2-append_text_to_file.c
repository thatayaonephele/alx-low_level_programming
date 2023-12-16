#include "main.h"
/**
 * append_text_to_file - A function that appends at the end of file text data
 * @filename: A ptr pointing  to the file name
 * @text_content: The string contents to be appended at end of file
 * Return: 1 on Success, else -1 on function failuire, file DNE,
 *  NULL filename,or absence of write permissions
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x;
	int y;
	int z;

	z = 0;
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[z])
			z++;
	}
	x = open(filename, O_WRONLY | O_APPEND);
	if (x < 0)
		return (-1);
	y = write(x, text_content, z);
	if (y < 0)
		return (-1);
	close(x);
	return (1);
}
