#include "shell.h"

/**
 * _getdone - Searches for the environment string pointed to by name
 * @name: string containing the name of the requested variable.
 * @obs: shell data
 * Return: the associated value to the string or NULL
 */

char *_getdone(op_t *obs, const char *name)
{
	int i = 0, j = 0, k = 0, len1, len2;
	char *new;
	char **env;

	env = obs->environ;
	i = 0;
	len1 = strlen((void *)name);
	while (env[i])
	{
		j = strncmp(env[i], (void *)name, len1);
		if (j == 0 && (env[i][len1] == '='))
		{
			len2 = strlen(env[i]);
			new = malloc(sizeof(char) * (len2 - len1 + 1));
			if (new == NULL)
			{
				free(new);
				return (NULL);
			}

			j = len1 + 1;
			k = 0;
			while (env[i][j])
			{
				new[k] = env[i][j];
				j++;
				k++;
			}
			new[k] = '\0';
			return (new);
		}
		i++;
	}
	return (NULL);
}
