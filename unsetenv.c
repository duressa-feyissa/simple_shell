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

	for (i = 0; obs->envn[i]; i++)
		;

	newenviron = malloc(sizeof(char *) * i);
	if (!newenviron)
		return (1);

	i = j = 0;
	while (obs->envn[i])
	{
		envv = _strdup(obs->envn[i]);
		var_env = strtok(envv, "=");
		if (_strcmp(var_env, (void *)name) == 0)
		{
			free(obs->envn[i++]);
			free(envv);
			continue;
		}
		free(envv);
		newenviron[j++] = obs->envn[i++];
	}
	newenviron[j++] = NULL;
	free(obs->envn);
	obs->envn = newenviron;

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

	if (obs->argv[1])
		fl = _unsetenv(obs, obs->argv[1]);

	if (fl != 0)
		perror("Error");
	return (0);
}
