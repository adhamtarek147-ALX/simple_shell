#include "shell.h"
/**
 * adham_exit_shell - exits the shell
 * @cmd: cmd
 * @arg: arg
 * @s: stat
 * @i: idx
 * Return: 0
 */
void adham_exit_shell(char **cmd, char **arg, int *s, int i)
{
	int adham_exit_val = 0;
	char *idx;
	char mg[] = ": exit: illegal number: ";

	if (*s)
		adham_exit_val = *s;

	if (cmd[1])
	{
		if (adham_is_positive_num(cmd[1]))
		{
			adham_exit_val = adham_atoi(cmd[1]);
		}

		else
		{
			idx = adham_itoa(i);
			write(STDERR_FILENO, arg[0], adham_strlen(arg[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, adham_strlen(idx));
			write(STDERR_FILENO, mg, adham_strlen(mg));
			write(STDERR_FILENO, cmd[1], adham_strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx), idx = NULL;
			adham_freearr(cmd);
			*s = 2;
			return;
		}
	}
	adham_freearr(cmd);
	exit(adham_exit_val);
}
