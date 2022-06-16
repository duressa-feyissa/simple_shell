#include "shell.h"

/**
 * makeenv - create an environment variable
 *
 * @var: variable name
 * @val: variable value
 * Return: the env variable if found otherwise NULL
 */
char *makeenv(char *var, char *val)
{
	size_t len_var, len_val;
	char *env;

	len_var = _strlen(var);
	len_val = _strlen(val);
	env = malloc(sizeof(char) * (len_val + len_var + 2));
	if (!env)
		return (NULL);
	_strcpy(env, var);
	_strcat(env, "=");
	_strcat(env, val);
	_strcat(env, "\0");

	return (env);
}

/**
 * _setenv - change or add an environment variable
 *
 * @obs: shell data
 * @name: variable name
 * @value: variable value
 * @overwrite: 0 to avoid change otherwise any other integer
 * Return: 0 if successful otherwise 1
 */
int _setenv(op_t *obs, char *name, char *value, int overwrite)
{
	unsigned int i;
	char *envv, *var_env, *backup, *newenv;

	for (i = 0; obs->envn[i]; i++)
	{
		envv = _strdup(obs->envn[i]);
		var_env = strtok(envv, "=");
		if (_strcmp(var_env, name) == 0)
		{
			if (overwrite == 0)
				return (0);
			backup = _strdup(obs->envn[i]);
			free(obs->envn[i]);
			newenv = makeenv(name, value);
			if (!newenv)
			{
				free(envv);
				obs->envn[i] = backup;
				return (1); /* TODO => Set errno */
			}
			obs->envn[i] = newenv;
			free(envv);
			free(backup);
			return (0);
		}
		free(envv);
	}

	obs->envn = _realloc2(obs->envn, i, sizeof(char *) * (i + 2));
	obs->envn[i] = makeenv(name, value);
	obs->envn[i + 1] = NULL;

	return (0);
}

/**
 * h_setenv - set variable enviroment
 * @obs: shell data
 *
 * Return: 0 on success
 */
int h_setenv(op_t *obs)
{
	int fl = 1;

	if (obs->argv[1] && obs->argv[2])
		fl = _setenv(obs, obs->argv[1], obs->argv[2], 1);
	if (fl != 0)
		perror("Error");

	return (0);
}
