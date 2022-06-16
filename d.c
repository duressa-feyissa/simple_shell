#include "shell.h"
#include "_string.h"
#include <string.h>
#include "util.h"


/**
 * env_cmp - compares a name with env key
 *
 * @envvar: env variable
 * @name: name to compare
 *
 * Return: 0 if not match else an integer
 */
int env_cmp(const char *envvar, const char *name)
{
	unsigned int i;

	for (i = 0; envvar[i] != '='; i++)
		if (envvar[i] != name[i])
			return (0);

	return (++i);
}

/**
 * _getenv - Gets the value of an environment variable
 *
 * @_environ: env variables
 * @name: given name
 * Return: the env variable if found otherwise NULL
 */
char *_getenv(char **_environ, const char *name)
{
	unsigned int i;
	int offset;

	for (i = 0; _environ[i]; i++)
	{
		offset = env_cmp(_environ[i], name);
		if (offset)
			return (_environ[i] + offset);
	}

	return (NULL);
}

/**
 * hsh_env - prints env variables
 *
 * @shell: shell data
 * Return: 0 for success otherwise another integer
 */
int hsh_env(shell_t *shell)
{
	int i = 0, len;

	/* Todo -> print envs */
	while (shell->environ[i] != NULL)
	{
		len = _strlen(shell->environ[i]);
		write(STDOUT_FILENO, shell->environ[i], len + 1);
		write(STDOUT_FILENO, "\n", 2);
		i++;
	}
	return (0);
}
