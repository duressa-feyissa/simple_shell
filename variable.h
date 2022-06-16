#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>

/**
 * struct var - variable
 *
 * @value: value
 * @len: length of the value
 * @len_var: length of equivalent variable
 * @next: pointer to next
 */
typedef struct var
{
	char *value;
	size_t len;
	size_t len_var;
	struct var *next;
} var_t;

void free_varlist(var_t **h);
var_t *add_varnode(var_t **h, char *value, int len_var);

#endif /* TOKEN_H */
