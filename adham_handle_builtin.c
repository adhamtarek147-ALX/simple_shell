#include "shell.h"
/**
 * adham_is_builtin - checks command built_in
 * @cmd: comm
 * Return: if command 1
 * otherwise, 0
 */

int adham_is_builtin(char *cmd)
{
	char *builtt[] = {
		"exit", "env", NULL};
	int ind;

	for (ind = 0; builtt[ind]; ind++)
	{
		if (strcmp(cmd, builtt[ind]) == 0)
			return (1);
	}
	return (0);
}
/**
 * adham_handle_builtin - determines type
 * @cmd: cmd
 * @arg: arg
 * @s: stat
 * @i: idx
 * Return: no
 */
void adham_handle_builtin(char **cmd, char **arg, int *s, int i)
{
	if (strcmp(cmd[0], "exit") == 0)
		adham_exit_shell(cmd, arg, s, i);
	else if (strcmp(cmd[0], "env") == 0)
		adham_print_env(cmd, s);
}
