#include "shell.h"
#include "util.h"

/**
 * remove_comment - removes comments from s.
 *
 * @s: Given string
 * Return: String without comment
 * If there is no string return NULL
 */
char *remove_comment(char *s)
{
	unsigned int len, i = 0;

	for (len = 0, i = 0; s[len]; len++)
	{
		if (s[len] == '#')
		{
			if (len == 0)
			{
				free(s);
				return (NULL);
			}
			if (s[len - 1] == ' ' || s[len - 1] == '\t')
				i = len;
		}
	}

	if (i != 0)
	{
		s = _realloc(s, len, i + 1);
		s[i] = '\0';
	}

	return (s);
}

/**
 * analyze_cmd - performs comment removal and variable expansion
 * on string
 * @shell: shell data
 * @cmd: command input
 * Return: String without comment
 * If there is no string return NULL
 */
char *analyze_cmd(shell_t *shell, char *cmd)
{
	(void) shell;

	cmd = remove_comment(cmd);
	if (!cmd)
		return (NULL);

	/* Variable expansion */
	cmd = exp_variables(shell, cmd);
	if (!cmd)
		return (NULL);

	return (cmd);
}
