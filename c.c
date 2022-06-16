#include "shell.h"
#include "_string.h"
#include <limits.h>

/**
 * cd_to - Changes the current directory of the process
 * to a given path
 *
 * @shell: shell data
 * @path: directory to change to
 */
void cd_to(shell_t *shell, char *path)
{
	char cwd[PATH_MAX], *cwd_dup, *nwd;

	getcwd(cwd, sizeof(cwd)); /* Get current directory */
	cwd_dup = _strdup(cwd);

	if (chdir(path) != 0)
	{
		free(cwd_dup);
		write_error(shell, 2);
		return;
	}

	getcwd(cwd, sizeof(cwd));
	nwd = _strdup(cwd);

	_setenv(shell, "OLDPWD", cwd_dup, 1);
	_setenv(shell, "PWD", nwd, 1);

	free(cwd_dup);
	free(nwd);
}

/**
 * cd_home - Changes the current directory of the process
 * to the path in "HOME" env variable
 *
 * @shell: shell data
 */
void cd_home(shell_t *shell)
{
	char *home;

	home = _getenv(shell->environ, "HOME");
	if (home)
		cd_to(shell, home);
}

/**
 * cd_prev - Changes the current directory of the process
 * to the previous path
 *
 * @shell: shell data
 */
void cd_prev(shell_t *shell)
{
	char *prwd, cwd[PATH_MAX], *message;
	int len;

	prwd = _getenv(shell->environ, "OLDPWD");
	if (prwd)
		cd_to(shell, prwd);

	getcwd(cwd, sizeof(cwd));
	len = _strlen(cwd) + 1;

	message = malloc(sizeof(char) * (len + 1));
	_strcpy(message, cwd);
	_strcat(message, "\n\0");
	write(STDOUT_FILENO, message, len);

	free(message);
}

/**
 * hsh_cd - Handle cd buit-in
 *
 * @shell: shell data
 * Return: 0 for success otherwise another integer
 */
int hsh_cd(shell_t *shell)
{
	if (shell->argv[1] == NULL || (_strcmp(shell->argv[1], "~") == 0))
		cd_home(shell);
	else if (_strcmp(shell->argv[1], "-") == 0)
		cd_prev(shell);
	else
		cd_to(shell, shell->argv[1]);
	return (0);
}
