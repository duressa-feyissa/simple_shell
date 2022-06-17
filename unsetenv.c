#include "shell.h"

/**
 * _unsetenv - unset variable enviroment
 * @obs: shell data
 * @name: value to unset
 * Return: 0 on succes otherwise -1
 */
int _unsetenv(op_t *obs, const char *name)
{
	unsigned int i, j;
	char *envv, *var_env, **newenviron;

	if (!_getdone(obs, name))
		return (0);

	for (i = 0; obs->environ[i]; i++)
		;

	newenviron = malloc(sizeof(char *) * i);
	if (!newenviron)
		return (1);

	i = j = 0;
	while (obs->environ[i])
	{
		envv = _strdup(obs->environ[i]);
		var_env = strtok(envv, "=");
		if (_strcmp(var_env, (void *)name) == 0)
		{
			free(obs->environ[i++]);
			free(envv);
			continue;
		}
		free(envv);
		newenviron[j++] = obs->environ[i++];
	}
	newenviron[j++] = NULL;
	free(obs->environ);
	obs->environ = newenviron;

	return (0);
}

/**
 * h_unsetenv - unset variable enviroment
 * @obs: shell data
 *
 * Return: 0 on success
 */
int h_unsetenv(op_t *obs)
{
	int fl = 1;

	if (obs->av[1])
		fl = _unsetenv(obs, obs->av[1]);

	if (fl != 0)
		write_err(obs, -1);
	return (0);
}
