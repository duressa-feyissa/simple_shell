#include "shell.h"
#include "_string.h"

/**
 * get_builtin_handl - gets appropriate handler for a supported
 * builtin command
 *
 * @command: input command
 * Return: function pointer to the handler
 */
int (*get_builtin_handl(const char *command))(shell_t *shell)
{
	unsigned int i;
	builtin_t builtins[] = {
		{ "exit", hsh_exit },
		{ "env", hsh_env },
		{ "cd", hsh_cd },
		{ "setenv", hsh_setenv },
		{ "unsetenv", hsh_unsetenv },
		{ NULL, NULL }
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(command, builtins[i].name) == 0)
			return (builtins[i].handl);
	}
	return (NULL);
}
