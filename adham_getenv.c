#include "shell.h"

/**
 * adham_getenv - get env var
 *
 * @varia: ssd
 *
 * Return: 1 or 0
 */

char *adham_getenv(char *varia)
{
	char *temp, *k, *environment, *value;
	int ind;

	for (ind = 0; environ[ind]; ind++)
	{
		temp = adham_strdup(environ[ind]);
		k = strtok(temp, "=");
		if (strcmp(k, varia) == 0)
		{
			value = strtok(NULL, "\n");
			environment = adham_strdup(value);
			free(temp);
			return (environment);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
