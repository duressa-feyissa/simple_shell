#include "shell.h"
#include "variable.h"
#include "_string.h"
#include <string.h>

/**
 * free_varlist - frees the variable single linked list
 * @h: head of the singly linked list
 */
void free_varlist(var_t **h)
{
	var_t *c, *temp;

	if (*h == NULL)
		return;

	c = *h;
	while ((temp = c) != NULL)
	{
		c = c->next;
		free(temp);
	}
	*h = NULL;
}

/**
 * add_varnode - Add a value to variable
 *
 * @h: head of the singly linked list
 * @value: value of the variable
 * @len_var: length of variable name
 *
 * Return: head of the singly linked list
 */
var_t *add_varnode(var_t **h, char *value, int len_var)
{
	var_t *c, *n;

	n = malloc(sizeof(var_t));
	if (n == NULL)
		return (NULL);

	n->value = value;
	n->len = value ? _strlen(value) : 0;
	n->len_var = len_var;
	n->next = NULL;

	c = *h;

	if (c == NULL)
	{
		*h = n;
	}
	else
	{
		while (c->next)
			c = c->next;
		c->next = n;
	}

	return (*h);
}
