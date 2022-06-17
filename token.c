#include "shell.h"
#include "util.h"
#include <string.h>

/**
 * tokenize - splits a string into an array
 *
 * @s: input string
 * Return: an array
 */
char **tokenize(char *s)
{
	char **argv;
	char *token;
	size_t bufsize, i;

	bufsize = TOKEN_BUFSIZE;
	argv = malloc(sizeof(char *) * (bufsize));
	if (!argv)
		return (NULL);

	token = strtok(s, TOKEN_DELIM);
	if (!token)
	{
		free(argv);
		return (NULL);
	}
	argv[0] = token;

	for (i = 1; token; i++)
	{
		if (i == bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			argv = _realloc2(argv, sizeof(char *) * i, sizeof(char *) * bufsize);
			if (argv == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
		argv[i] = token;
	}

	return (argv);
}
