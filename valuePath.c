#include "shell.h"

/**
 * valuePath - Separate the path in new strings.
 * @av: command
 * @env: Variable enviroment
 *
 * Return: Pointer to strings.
 */
int valuePath(char **av, char **env)
{
	char *tok = NULL, *pathRela = NULL, *pathAbs = NULL;
	size_t valPath, len;
	struct stat st;

	if (stat(*av, &st) == 0)
		return (-1);
	pathRela = _getPath(env);
	if (pathRela == NULL)
		return (-1);
	tok = strtok(pathRela, ":");
	len = _strlen(*av);
	while (tok)
	{
		valPath = _strlen(tok);
		pathAbs = malloc(sizeof(char) * (valPath + len + 2));
		if (pathAbs == NULL)
		{
			free(pathAbs);
			return (-1);
		}
		_strcpy(pathAbs, tok);
		_strcat(pathAbs, "/");
		_strcat(pathAbs, *av);
		_strcat(pathAbs, "\0");

		if (stat(pathAbs, &st) == 0)
		{
			*av = pathAbs;
			free(pathRela);
			return (0);
		}
		free(pathAbs);
		tok = strtok(NULL, ":");
	}
	tok = '\0';
	free(pathRela);
	return (-1);
}
