#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 1024
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"
#define EXIT_IND 2

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/**
 * struct shell - shell data for current session
 *
 * @argv: argument vector
 * @command: input command
 * @environ: env variables
 * @name: the program name
 * @count: counts number of processes
 * @exitcode: the value the code exits
 * @pid: pid of current process
 */
typedef struct shell
{
	char **argv;
	char *command;
	char **environ;
	char *name;
	int count;
	int exitcode;
	char *pid;
} shell_t;

/**
 * struct builtin - builtins
 *
 * @name: name of builtin
 * @handl: builtin handler
 */
typedef struct builtin
{
	char *name;
	int (*handl)(shell_t *shell);
} builtin_t;

extern char **environ;

/* setup */
void initialize(shell_t *shell, char **av);
void uninitialize(shell_t *shell);
void handl_signint(int sig);
void repl(shell_t *shell);

/* env */
char *_getenv(char **_environ, const char *name);
int _setenv(shell_t *shell, char *name, char *value, int overwrite);

/* executor */
int parse_command(shell_t *shell, char *command);
int execute(shell_t *shell);

/* builtins */
int (*get_builtin_handl(const char *cmd))(shell_t *shell);
int hsh_exit(shell_t *shell);
int hsh_env(shell_t *shell);
int hsh_cd(shell_t *shell);
int hsh_setenv(shell_t *shell);
int hsh_unsetenv(shell_t *shell);

/* utils */
void prompt(void);
char *read_line(int *chr);
char **tokenize(char *s);
char *analyze_cmd(shell_t *shell, char *cmd);
char *exp_variables(shell_t *shell, char *s);

/* error */
void write_error(shell_t *shell, int status);

#endif /* SHELL_H */
