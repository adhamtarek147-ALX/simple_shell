#include "shell.h"
/**
 * adham_is_positive_num - checks if string positive
 * @s: str
 * Return: 1
 * otherwise, it returns 0
 */
int adham_is_positive_num(char *s)
{
	int ind;

	if (!s)
		return (0);
	for (ind = 0; s[ind]; ind++)
	{
		if (s[ind] < '0' || s[ind] > '9')
			return (0);
	}
	return (1);
}
/**
 * adham_atoi - conversion of strs
 * @s: str
 * Return: number
 */
int adham_atoi(char *s)
{
	int ind, number = 0;

	for (ind = 0; s[ind]; ind++)
	{
		number *= 10;
		number += (s[ind] - '0');
	}
	return (number);
}
