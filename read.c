#include "main.h"

/**
 *  _line - reads characters from the standard input
 *  @chr: the count of characters read
 *
 *  Return: pointer to the output string
 */
char *_line(int *chr)
{
	char *input = NULL;
	size_t bufsize = SIZE;

	*chr = getline(&input, &bufsize, stdin);

	return (input);
}
