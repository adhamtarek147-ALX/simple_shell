#include "shell.h"

/**
 * adham_main - main
 *
 * @ac: int
 * @argv : shell's name
 *
 * Return: 1 or 0
 */

int main(int ac, char **argv)
{
	char *lne = NULL;
	char **command = NULL;
	int stat = 0, idx = 0;

	(void)ac;

	while (1)
	{
		lne = adham_read_line();
		if (lne == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		idx++;
		command = adham_tokenise(lne);
		if (!command)
			continue;
		if (adham_is_builtin(command[0]))
			adham_handle_builtin(command, argv, &stat, idx);
		else
			stat = adham_execute(command, argv, idx);
	}
	return (WEXITSTATUS(stat));
}
