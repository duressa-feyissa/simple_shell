#include "shell.h"

/**
 * start - setup shell variables
 * @obs: shell data
 * @argv: argument
 *
 * Return: Void
 */
void start(op_t *obs, char **argv)
{
	unsigned int i;

	obs->av = NULL;
	obs->cmd = NULL;
	obs->name = argv[0];
	obs->exCo = 0;
	obs->count = 1;

	i = 0;
	while (environ[i])
		i++;
	obs->environ = malloc(sizeof(char *) * (i + 1));
	if (obs->environ == NULL)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return;
	}

	i = 0;
	while (environ[i])
	{
		obs->environ[i] = _strdup(environ[i]);
		i++;
	}
	obs->environ[i] = NULL;
}

/**
 * unstart - frees shell data
 * @obs: shell data
 *
 * Return: Void
 */
void unstart(op_t *obs)
{
	unsigned int i;

	for (i = 0; obs->environ[i]; i++)
	{
		free(obs->environ[i]);
	}
	free(obs->environ);
}
