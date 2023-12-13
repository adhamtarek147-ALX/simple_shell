#include "shell.h"

/**
 * adham_read_line - read lne
 *
 * Return: lne
 */

char *adham_read_line()
{
	char *l = NULL;
	size_t a = 0;
	ssize_t linee;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	linee = getline(&l, &a, stdin);
	if (linee < 0)
	{
		free(l);
		return (NULL);
	}
	return (l);
}
