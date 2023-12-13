#include "shell.h"

/**
 * adham_tokenise - transform lines to tokens
 *
 * @ln : ln
 *
 * Return: token
 */

char **adham_tokenise(char *ln)
{
	int ind = 0, ind2 = 0;
	char **command = NULL;
	char *temp = NULL, *token = NULL;

	temp = adham_strdup(ln);
	token = strtok(temp, " \n\t");
	if (!token)
	{
		free(ln), ln = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		token = strtok(NULL, " \n\t");
		ind++;
	}
	free(temp), temp = NULL;

	command = malloc(sizeof(char *) * (ind + 1));
	if (!command)
	{
		free(ln), ln = NULL;
		return (NULL);
	}
	token = strtok(ln, " \n\t");
	while (token)
	{
		command[ind2] = adham_strdup(token);
		token = strtok(NULL, " \n\t");
		ind2++;
	}
	command[ind2] = NULL;
	free(ln), ln = NULL;
	return (command);
}
