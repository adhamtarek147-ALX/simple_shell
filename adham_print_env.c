#include "shell.h"
/**
 * adham_print_env - print env var
 *
 * @cmd: cmd
 * @s: stat
 * Return: no
 */
void adham_print_env(char **cmd, int *s)
{
	int idx;

	for (idx = 0; environ[idx]; idx++)
	{
		write(STDOUT_FILENO, environ[idx], adham_strlen(environ[idx]));
		write(STDOUT_FILENO, "\n", 1);
	}
	adham_freearr(cmd);
	(*s) = 0;
}
