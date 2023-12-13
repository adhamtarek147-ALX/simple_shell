#include "shell.h"
/**
 * adham_strlen - len of str
 * @s: str
 * Return: int len of str
 */

int adham_strlen(char *s)
{
	int ind = 0;

	if (!s)
		return (0);
	while (*s++)
		ind++;
	return (ind);
}
/**
 * adham_strcat - conc two strs
 * @destination: dest
 * @source: src
 *
 * Return: ptr
 */
char *adham_strcat(char *destination, char *source)
{
	char *a = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (a);
}

/**
 * adham_strcpy - cpy str
 * @destination: dest
 * @source: src
 *
 * Return: ptr
 */
char *adham_strcpy(char *destination, char *source)
{
	int ind = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[ind])
	{
		destination[ind] = source[ind];
		ind++;
	}
	destination[ind] = '\0';
	return (destination);
}
