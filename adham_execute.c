#include "shell.h"

/**
 * adham_execute - executes
 *
 * @args: token arg
 * @argv : shell's name
 * @i : itr
 * Return: 1 or 0
 */

int adham_execute(char **args, char **argv, int i)
{
	pid_t fk;
	int stat;
	char *command;

	command = adham_getpath(args[0]);
	if (!command)
	{
		free(command);
		adham_printerr(argv[0], args[0], i);
		adham_freearr(args);
		exit(127);
	}

	fk = fork();
	if (fk == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			free(command), command = NULL;
			adham_freearr(args);
			exit(0);
		}
	}
	else
	{
		waitpid(fk, &stat, 0);
		adham_freearr(args);
		free(command);
	}

	return (WEXITSTATUS(stat));
}
