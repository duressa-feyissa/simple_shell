#include "shell.h"
#include "_string.h"
#include <string.h>
#include "util.h"

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
 * @shell: shell data
 * @name: variable name
 * @value: variable value
 * @overwrite: 0 to avoid change otherwise any other integer
 * Return: 0 if successful otherwise 1
 */
int _setenv(shell_t *shell, char *name, char *value, int overwrite)
{
	unsigned int i;
	char *envv, *var_env, *backup, *newenv;

	for (i = 0; shell->environ[i]; i++)
	{
		envv = _strdup(shell->environ[i]);
		var_env = strtok(envv, "=");
		if (_strcmp(var_env, name) == 0)
		{
			if (overwrite == 0)
				return (0);
			backup = _strdup(shell->environ[i]);
			free(shell->environ[i]);
			newenv = makeenv(name, value);
			if (!newenv)
			{
				free(envv);
				shell->environ[i] = backup;
				return (1); /* TODO => Set errno */
			}
			shell->environ[i] = newenv;
			free(envv);
			free(backup);
			return (0);
		}
		free(envv);
	}

	shell->environ = _realloc2(shell->environ, i, sizeof(char *) * (i + 2));
	shell->environ[i] = makeenv(name, value);
	shell->environ[i + 1] = NULL;

	return (0);
}

/**
 * _unsetenv - an environment variable
 *
 * @shell: shell data
 * @name: variable name
 * Return: 0 if successful otherwise 1
 */
int _unsetenv(shell_t *shell, char *name)
{
	unsigned int i, j;
	char *envv, *var_env, **newenviron;

	if (!_getenv(shell->environ, name)) /* the env does not exist */
		return (0);

	for (i = 0; shell->environ[i]; i++)
		;

	newenviron = malloc(sizeof(char *) * i);
	if (!newenviron)
		return (1); /* Handle error */

	i = j = 0;
	while (shell->environ[i])
	{
		envv = _strdup(shell->environ[i]);
		var_env = strtok(envv, "=");
		if (_strcmp(var_env, name) == 0)
		{
			free(shell->environ[i++]);
			free(envv);
			continue;
		}
		free(envv);
		newenviron[j++] = shell->environ[i++];
	}
	newenviron[j++] = NULL;
	free(shell->environ);
	shell->environ = newenviron;

	return (0);
}

/**
 * hsh_setenv - prints env variables
 *
 * @shell: shell data
 * Return: 0 for success otherwise another integer
 */
int hsh_setenv(shell_t *shell)
{
	int flag = 1;

	if (shell->argv[1] && shell->argv[2])
		flag = _setenv(shell, shell->argv[1], shell->argv[2], 1);

	if (flag != 0)
		write_error(shell, -1);

	return (0);
}

/**
 * hsh_unsetenv - prints env variables
 *
 * @shell: shell data
 * Return: 0 for success otherwise another integer
 */
int hsh_unsetenv(shell_t *shell)
{
	int flag = 1;

	if (shell->argv[1])
		flag = _unsetenv(shell, shell->argv[1]);

	if (flag != 0)
		write_error(shell, -1);

	return (0);
}
