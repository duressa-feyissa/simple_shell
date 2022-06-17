#include "shell.h"
#include "util.h"
#include "_string.h"
#include <string.h>
/**
 * _which - find the file for a command
 *
 * @env: environ
 * @command: command input
 * Return: 0 on failure otherwise 1
 */
char *_which(char **env, char *command)
{
	char *str, *str_dup, *spath, *doc;
	int len_spath, len_cmd;
	struct stat st;

	str = _getenv(env, "PATH");
	if (str == NULL)
		return (NULL);
	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return (_strdup(command));

	str_dup = _strdup(str);
	len_cmd = _strlen(command);
	spath = strtok(str_dup, ":");
	while (spath)
	{
		len_spath = _strlen(spath);
		doc = malloc(sizeof(char) * (len_spath + len_cmd + 2));
		if (doc == NULL)
		{
			free(str_dup);
			write(STDERR_FILENO, ": allocation error\n", 18);
			exit(EXIT_FAILURE);
		}
		_strcpy(doc, spath);
		_strcat(doc, "/");
		_strcat(doc, command);
		_strcat(doc, "\0");
		if (stat(doc, &st) == 0)
		{
			free(str_dup);
			return (doc);
		}
		free(doc);
		spath = strtok(NULL, ":");
	}
	free(str_dup);
	return (NULL);
}

/**
 * check_exe - check if a path can be executed
 *
 * @str: path
 * Return: 0 on success otherwise 1
 */
int check_exe(char *str)
{
	struct stat st;
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == '/')
				i++;
			else if (str[i + 1] == '.' && str[i + 2] == '/')
				i = i + 2;
			else
				return (1);
		}
		i++;
	}
	if (stat(str, &st) == 0)
		return (0);
	return (1);
}

/**
 * check_error - check_error function
 * @obs: shell data
 * @doc: file
 * Return: Success of execution
 */

int check_error(op_t *obs, char *doc)
{
	if (!doc)
	{
		write_err(obs, 127);
		return (1);
	}
	if (access(doc, X_OK) == -1)
	{
		write_err(obs, 126);
		return (1);
	}
	return (0);
}


/**
 * _exe - execute the command
 * @obs: shell data
 *
 * Return: Success of execution
 */
int _exe(op_t *obs)
{
	pid_t pid;
	int status, fl;
	char *doc;

	fl = check_exe(obs->av[0]);
	if (fl == 0)
	{
		doc = _strdup(obs->av[0]);
	}
	else
	{
		doc = _which(obs->env, obs->av[0]);
		if (!doc)
		{
			write_err(obs, 127);
			return (1);
		}
	}
	if (check_error(obs, doc) == 1)
		return (1);
	pid = fork();

	if (pid == 0)
	{
		execve(doc, obs->av, obs->env);
	}
        else if (pid < 0)
        {
                perror(obs->av[0]);
                return (1);
        }
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(doc);
	obs->exCo = status / 256;
	return (1);
}
