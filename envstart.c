#include "shell.h"

/**
 * _envStart - Make copy of the environs
 * @obs: shell data
 * @env: enviromental variable
 *
 * Return: Void
 */
void _envStart(op_t *obs, char **env)
{
	unsigned int i;

	obs->exCo = 0;
	i = 0;
	while (env[i])
		i++;

	obs->envn = malloc(sizeof(char *) * (i + 2));
	if (obs->envn == NULL)
	{
		perror("Error");
		return;
	}

	i = 0;
	while (env[i])
	{
		obs->envn[i] = _strdup(env[i]);
		i++;
	}
	obs->envn[i] = NULL;
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

	for (i = 0; obs->envn[i]; i++)
	{
		free(obs->envn[i]);
	}
	free(obs->envn);
}
