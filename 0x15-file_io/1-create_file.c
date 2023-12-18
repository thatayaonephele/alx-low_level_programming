#include "main.h"

/**
 * create_file - A function responsible for the file creation
 * @filename: A pointing to the destination file name being created
 * @text_content: A ptr pointing to a string of chr being written
 * Return: 1 on Successful file creation else -1 on failuire
 */

int create_file(const char *filename, char *text_content)
{
	int x; /*opening var*/
	int y; /*writing var*/
	int z; /*size count loop var*/

	if (filename == NULL) /*test if name of file exists*/
		return (-1);

	if (text_content != NULL) /*test if contents being written exists*/
	{
		for (; text_content[z];)
			z++; /*inc cnt as long as text at loop var exists*/
	}

	x = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600); /*piping of flags*/
	y = write(x, text_content, z); /*write nbytes */

	if (x == -1 || y  == -1) /*test if open& writing was successful*/
		return (-1);
	close(x); /*After writing contents close file*/
	return (1);
}
