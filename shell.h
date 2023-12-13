#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>

extern char **environ;
void adham_freearr(char **arr);
void adham_printerr(char *nm, char *cmd, int i);
char *adham_itoa(int n);
void adham_reverse_string(char *str, int len);
int adham_atoi(char *s);
int adham_is_positive_num(char *s);
char *adham_strcpy(char *dest, char *str);
char *adham_strcat(char *dest, char *str);
char *adham_strdup(const char *str);
int adham_strlen(char *s);
char **adham_tokenise(char *ln);
char *adham_read_line();
int adham_execute(char **args, char **argv, int i);
char *adham_getpath(char *cmd);
char *adham_getenv(char *varia);
int adham_is_builtin(char *cmd);
void adham_handle_builtin(char **cmd, char **arg, int *s, int i);
void adham_print_env(char **cmd, int *s);
void adham_exit_shell(char **cmd, char **arg, int *s, int i);

#endif
