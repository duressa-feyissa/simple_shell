#include "main.h"

/**
 * find - find which builtin function
 * @str: command to be checked
 * Return: integer or NULL
 */
int (*find(char *str))(op_t *obs)
{
	ph type[] = {
		{"exit", exitfun},
		{"env", envfun},
		{NULL, NULL}
	};
	unsigned int i;

	i = 0;
	while (type[i].s)
	{
		if ((_strcmp(type[i].s, str)) == 0)
			return (type[i].find);
		i++;
	}
	return (NULL);
}
