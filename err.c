#include "shell.h"
#include "_string.h"
/**
 * error_message - displays error message to terminal
 * @obs: shell data
 * @message: error message
 * @status: error code
 */
void error_message(op_t *obs, char *message, int status)
{
	int l, l1, l2, l3, l4;
	char *count, *error;

	count = _itoa(obs->count);
	l1 = _strlen(obs->name);
	l2 = _strlen(count);
	l3 = _strlen(obs->av[0]);
	l4 = _strlen(message);
	l = l1 + 2 + l2 + 2 + l3 + l4;

	error = malloc(sizeof(char) * (l + 1));
	_strcpy(error, obs->name);
	_strcat(error, ": ");
	_strcat(error, count);
	_strcat(error, ": ");
	_strcat(error, obs->av[0]);
	_strcat(error, message);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, l);
	obs->exCo = status % 256;
	free(count);
	free(error);
}

/**
 * cd_error - patch the error message for cd
 * @obs: shell data
 * Return: error message
 */
char *cd_error(op_t *obs)
{
	char *message, *template = ": can't cd to ";
	int len, len2;

	len = _strlen(template);
	len2 = _strlen(obs->av[1]);
	message = malloc(sizeof(char) * (len + len2 + 2));
	if (!message)
		return (NULL);

	_strcpy(message, template);
	_strcat(message, obs->av[1]);
	_strcat(message, "\n\0");

	return (message);
}

/**
 * exit_error - patch the error message for cd
 * @obs: shell data
 * Return: error message
 */
char *exit_error(op_t *obs)
{
	char *message, *template = ": Illegal number: ";
	int len, len2;

	len = _strlen(template);
	len2 = _strlen(obs->av[1]);
	message = malloc(sizeof(char) * (len + len2 + 2));
	if (message == NULL)
		return (NULL);

	_strcpy(message, template);
	_strcat(message, obs->av[1]);
	_strcat(message, "\n\0");

	return (message);
}

/**
 * write_err - write errors
 * @obs: the command
 * @status: error code
 */
void write_err(op_t *obs, int status)
{
	char *message = NULL;

	switch (status)
	{
		case -1:
			message = _strdup(": Unable to add/remove from environment\n");
			status = 0;
			break;
		case 126: /* Permission */
			message = _strdup(": Permission denied\n");
			break;
		case 127: /* Not found */
			message = _strdup(": not found\n");
			break;
		case 2:
			if (_strcmp(obs->av[0], "exit") == 0)
				message = exit_error(obs);
			else if (_strcmp(obs->av[0], "cd") == 0)
				message = cd_error(obs);
			break;
		default:
			message = _strdup(": not found\n");

	}

	if (message)
	{
		error_message(obs, message, status);
		free(message);
	}
}
