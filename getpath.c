#include "shell.h"

/**
 * _getPath - find enviromental path
 * @env: enviromental variable
 *
 * Return: enviromental path or NULL
 */
char *_getPath(char **env)
{
	int i = 0, j = 0, k = 0, len1, len2;
	char *new, *name;

	i = 0;
	name = "PATH";
	len1 = _strlen(name);
	while (env[i])
	{
		j = _strncmp(env[i], name, len1);
		if (j == 0 && (env[i][len1] == '='))
		{
			len2 = _strlen(env[i]);
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
