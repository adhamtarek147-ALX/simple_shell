#include "shell.h"
/**
 *adham_strdup - doubles str
 * @str: str
 *
 * Return: ptr
 */
char *adham_strdup(const char *str)
{
	char *ptr;
	int ind, length = 0;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	ptr = malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (NULL);
	for (ind = 0; ind <= length; ind++)
		ptr[ind] = str[ind];
	return (ptr);
}
