#include "main.h"

/**
 * path - find enviromental path
 * @env: enviromental variable
 *
 * Return: enviromental path or NULL
 */
char *path(char **env)
{
	int i = 0, j = 0, k = 0, len1, len2;
	char *new, *name;

	i = 0;
	name = "PATH";
	len1 = strlen(name);
	while (env[i])
	{
		j = strncmp(env[i], name, len1);
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

/**
 * PATH - make array of the enviromental path
 * @env: string of enviromental path
 *
 * Return: array of path or NULL
 */

char **PATH(const char *env)
{
	int i, j, k, count;
	const int _MAX = 128;
	char **new;

	if (env == NULL)
		return (NULL);

	count = 0;
	for (i = 0; env[i]; i++)
		if (env[i] == ':')
			count++;

	new = malloc(sizeof(char *) * (count + 2));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	for (i = 0; i < (count + 2); i++)
		new[i] = malloc(sizeof(char) * _MAX);

	k = 0;
	for (i = 0; i < (count + 1); i++)
	{
		for (j = 0; env[k] != ':' && env[k]; j++)
		{
			new[i][j] = env[k];
			k++;
		}
		k++;
		new[i][j] = '\0';
	}
	new[i] = NULL;

	return (new);
}

/**
 * freePATH - free the array of string
 * @new: array of string
 *
 * Return: Void
 */
void freePATH(char **new)
{
	int i;

	for (i = 0; new[i]; i++)
		free(new[i]);
	free(new);
}

/**
 * freepath - free the array
 * @token: string
 *
 * Return: Void
 */
void freepath(char *token)
{
	free(token);
}
