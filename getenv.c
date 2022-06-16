#include "main.h"

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
