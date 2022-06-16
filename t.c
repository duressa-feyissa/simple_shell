#include "shell.h"
#include "variable.h"
#include "_string.h"
#include <string.h>

/**
 * var_environ - checks for environment variables and add to the linked list
 *
 * @shell: shell data
 * @h: head of variable linked list
 * @offset: command substring starting with $
 * Return: the variable length
 */
int var_environ(shell_t *shell, var_t **h, char *offset)
{
	int i, j, k;

	for (i = 0; shell->environ[i]; i++)
	{
		for (j = 0, k = 1; shell->environ[i][j]; j++)
		{
			if (shell->environ[i][j] == '=')
			{
				*h = add_varnode(h, shell->environ[i] + j + 1, k);
				return (k - 1);
			}
			if (shell->environ[i][j] != offset[k])
				break;
			k++;
		}
	}

	for (k = 0; offset[k]; k++)
		if (offset[k] == ' ' || offset[k] == '\n' || offset[k] == '\t')
			break;

	*h = add_varnode(h, NULL, k);
	return (k);
}

/**
 * var_builtin - checks for built-in variables and add to the linked list
 *
 * @shell: shell data
 * @h: head of variable linked list
 * @offset: command substring starting with $
 * @exitcode: exit code in string
 * Return: -1 if not variable is added to the linked list
 * otherwise the variable length
 */
int var_builtin(shell_t *shell, var_t **h, char *offset, char *exitcode)
{
	switch (offset[1])
	{
	case '?':
		*h = add_varnode(h, exitcode, 2);
		return (1);
	case '$':
		*h = add_varnode(h, shell->pid, 2);
		return (1);
	case ' ':
	case '\t':
	case '\n':
	case '\0':
		*h = add_varnode(h, NULL, 0);
		return (0);
	}

	return (-1);
}

/**
 * link_variables - split input to a singly linked list
 *
 * @shell: shell data
 * @h: head of the singly linked list
 * @input: input string
 * @exitcode: exit code in string
 * Return: length of the new expanded command
 */
int link_variables(shell_t *shell, var_t **h, char *input, char *exitcode)
{
	unsigned int i, len;
	int flag = -1, count = 0;
	var_t *c;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '$')
		{
			flag = var_builtin(shell, h, input + i, exitcode);
			if (flag == -1)
				flag = var_environ(shell, h, input + i);
			i += flag;
		}
	}

	c = *h, len = _strlen(input);
	while (c)
		count += (c->len - c->len_var), c = c->next;

	return (len + count);
}

/**
 * rep_variables - split input to a singly linked list
 *
 * @h: head of the singly linked list
 * @in: input string
 * @new: new memory allocated string
 * @n: length of new string
 * Return: new string
 */
char *rep_variables(var_t **h, char *in, char *new, unsigned int n)
{
	var_t *c;
	unsigned int from, to, i;

	c = *h;
	for (from = to = 0; to < n; to++)
	{
		if (in[from] == '$')
		{
			if (!(c->len) && !(c->len_var))
			{
				new[to] = in[from];
				from++;
			}
			else if (!(c->len) && c->len_var)
			{
				for (i = 0; i < c->len_var; i++)
					from++;
				to--;
			}
			else if (c && c->value)
			{
				for (i = 0; i < c->len; i++)
					new[to++] = c->value[i];

				from += c->len_var;
				to--;
			}
			c = c->next;
		}
		else
		{
			new[to] = in[from];
			from++;
		}
	}

	return (new);
}

/**
 * exp_variables - expands variables
 *
 * @shell: shell data
 * @s: input string
 * Return: an array
 */
char *exp_variables(shell_t *shell, char *s)
{
	var_t *h;
	char *exp, *exitcode;
	int len;

	h = NULL;
	exitcode = _itoa(shell->exitcode);
	len = link_variables(shell, &h, s, exitcode);

	if (h == NULL)
	{
		free(exitcode);
		return (s);
	}

	exp = malloc(sizeof(char) * (len + 1));
	if (!exp)
	{
		free(exitcode);
		return (s);
	}

	exp[len] = '\0';
	exp = rep_variables(&h, s, exp, len);
	free(s);
	free_varlist(&h);
	free(exitcode);
	return (exp);
}
