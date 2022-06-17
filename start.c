#include "shell.h"
#include "util.h"
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
	obs->pid = _itoa(getpid());

	i = 0;
	while (environ[i])
		i++;
	obs->env = malloc(sizeof(char *) * (i + 1));
	if (obs->env == NULL)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return;
	}

	i = 0;
	while (environ[i])
	{
		obs->env[i] = _strdup(environ[i]);
		i++;
	}
	obs->env[i] = NULL;
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

	for (i = 0; obs->env[i]; i++)
	{
		free(obs->env[i]);
	}
	free(obs->env);
}
