#ifndef _MAIN_
#define _MAIN_

#define SIZE 1024
#define TOKEN_SIZE 128

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

/**
 * struct op - shell data for current session
 *
 * @av: argument vector
 * @cmd: input command
 * @env: env variables
 * @name: ______
 * @exCo: exit value
 */
typedef struct op
{
	char **av;
	char *cmd;
	char **env;
	char *name;
	int exCo;
} op_t;

/**
 * struct new - struct data
 * @s: string address holder
 * @find: find builtin command
 */
typedef struct new
{
	char *s;
	int (*find)(op_t *obs);
} ph;


/** String header file **/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _isdigit(char *c);
int _atoi(char *s);

/** Find the path **/
char *path(char **env);
char **PATH(const char *env);
void freePATH(char **new);
void freepath(char *token);

/** Memory allocation **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);


char **_strtok(char *str);
void start(op_t *obs, char **argv, char **env);
void _environ(op_t *obs, char **env);
void unstart(op_t *obs);
void prompt(void);
char *_line(int *chr);
void entry(op_t *obs);
int parse(op_t *obs, char *order);
int _exe(op_t *obs);

/** builtin **/
int (*find(char *str))(op_t *obs);
int exitfun(op_t *obs);
int envfun(op_t *obs);
char *_getenv(op_t *obs, const char *name);
int _setenv(op_t *obs, const char *name, const char *value, int overwrite);
int add_env(op_t *obs, const char *name, const char *value);
int _unsetenv(op_t *obs, const char *name);
int h_unsetenv(op_t *obs);
int h_setenv(op_t *obs);
int cdfun(op_t *obs);

/** getline **/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void _fix(char **lineptr, size_t *n, char *ptr, size_t i);

#endif
