#include "shell.h"

/**
 * envfun - Print the environment variables.
 * @obs: shell data.
 *
 * Return: Void
 */

int envfun(op_t *obs)
{
	char **env1;
	int i;

	env1 = obs->environ;
	i = 0;
	while (env1[i])
	{
		write(STDOUT_FILENO, env1[i], _strlen(env1[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
