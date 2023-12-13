#include "shell.h"

/**
 * adham_getpath - path complete
 * @cmd: command cmd
 * freearr - free arr
 * @arr:
 * Return: 1 or 0
 */

char *adham_getpath(char *cmd)
{
	char *path, *directory, *fullcommand;
	int ind;
	struct stat st;

	for (ind = 0; cmd[ind]; ind++)
	{
		if (cmd[ind] == '/')
		{
			if (stat(cmd, &st) == 0)
			{
				return (adham_strdup(cmd));
			}
			return (NULL);
		}
	}
	path = adham_getenv("PATH");
	if (!path)
		return (NULL);
	directory = strtok(path, ":");
	while (directory)
	{
		fullcommand = malloc(adham_strlen(directory) + adham_strlen(cmd) + 2);
		if (fullcommand)
		{
			adham_strcpy(fullcommand, directory);
			adham_strcat(fullcommand, "/");
			adham_strcat(fullcommand, cmd);
			if (stat(fullcommand, &st) == 0)
			{
				free(path);
				return (fullcommand);
			}
			free(fullcommand), fullcommand = NULL;

			directory = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
