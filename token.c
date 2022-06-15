#include "main.h"

/**
 * _strtok - String broken into smaller strings (tokens).
 * @str:
 *
 * Return: A pointer to the first token found in the string or NULL.
 */
char **_strtok(char *str)
{
	char **cmd;
	char *token;
	int i, size;

	if (!str)
	{
		return (NULL);
	}

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			size++;
		i++;
	}

	if (_strlen(str) == (size + 1))
		return (NULL);

	cmd = malloc(sizeof(char *) * (size + 2));
	if (cmd == NULL)
		return (NULL);

	i = 0;
	token = strtok(str, " \n\t\r");
	while (token)
	{
		cmd[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	cmd[i] = NULL;

	return (cmd);
}
