#include "shell.h"
#include "util.h"
#include "_string.h"
#include <string.h>

/**
 * _which - find the file for a command
 *
 * @_environ: env variables
 * @command: command input
 * Return: 0 on failure otherwise 1
 */
char *_which(char **_environ, char *command)
{
	char *path, *path_dup, *spath, *file;
	int len_spath, len_cmd;
	struct stat st;

	path = _getenv(_environ, "PATH");
	if (!path)
		return (NULL);

	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return (_strdup(command));

	path_dup = _strdup(path);
	len_cmd = _strlen(command);
	spath = strtok(path_dup, ":");
	while (spath != NULL)
	{
		len_spath = _strlen(spath);
		file = malloc(sizeof(char) * (len_spath + len_cmd + 2));
		if (!file)
		{
			free(path_dup);
			write(STDERR_FILENO, ": allocation error\n", 18);
			exit(EXIT_FAILURE);
		}
		_strcpy(file, spath);
		_strcat(file, "/");
		_strcat(file, command);
		_strcat(file, "\0");
		if (stat(file, &st) == 0)
		{
			free(path_dup);
			return (file);
		}
		free(file);
		spath = strtok(NULL, ":");
	}
	free(path_dup);

	return (NULL);
}

/**
 * can_execute - check if a path can be executed
 *
 * @path: path
 * Return: 0 on success otherwise 1
 */
int can_execute(char *path)
{
	struct stat st;
	int i;

	for (i = 0; path[i]; i++) /* is a valid path */
	{
		if (path[i] == '.')
		{
			if (path[i + 1] == '/')
				i++;
			else if (path[i + 1] == '.' && path[i + 2] == '/')
				i += 2;
			else
				return (1);
		}
	}

	if (stat(path, &st) == 0)
	{
		return (0);
	}

	return (1);
}

/**
 * check_error - check for possible errors for file to be executed
 *
 * @shell: shell data
 * @file: file to be execute
 * Return: 0 for success otherwise 1
 */
int check_error(shell_t *shell, char *file)
{
	if (file == NULL)
	{
		write_error(shell, 127);
		return (1);
	}

	if (access(file, X_OK) == -1)
	{
		write_error(shell, 126);
		return (1);
	}

	return (0);
}

/**
 * execute - executes a command
 *
 * @shell: shell data
 * Return: 0 on success otherwise 1
 */
int execute(shell_t *shell)
{
	pid_t pid;
	int sys, flag;
	char *file;

	/* Check if file is execuatable non-PATH path */
	flag = can_execute(shell->argv[0]);
	if (flag == 0)
	{
		file = _strdup(shell->argv[0]);
	}
	else
	{
		file = _which(shell->environ, shell->argv[0]);
		if (!file)
		{
			write_error(shell, 127);
			return (1);
		}
	}
	if (check_error(shell, file) == 1)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		execve(file, shell->argv, shell->environ);
	}
	else if (pid < 0)
	{
		perror(shell->argv[0]);
		return (1);
	}
	else
	{
		do {
			waitpid(pid, &sys, WUNTRACED);
		} while (!WIFEXITED(sys) && !WIFSIGNALED(sys));
	}
	free(file), shell->exitcode = sys / 256;
	return (1);
}
