#include "shell.h"

/**
 * adham_freearr - frees the array
 *
 * @arr: array
 *
 * Return: 1
 */

void adham_freearr(char **arr)
{
	int ind;

	if (!arr)
		return;

	for (ind = 0; arr[ind] != NULL; ind++)
		free(arr[ind]), arr[ind] = NULL;
	free(arr), arr = NULL;
}

/**
 *adham_itoa - frees the array
 *
 * @n: number
 *
 * Return: 1
 */

char *adham_itoa(int n)
{
	char buff[20];
	int ind = 0;

	if (n == 0)
		buff[ind++] = '0';
	else
	{
		while (n > 0)
		{
			buff[ind++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buff[ind] = '\0';
	adham_reverse_string(buff, ind);
	return (strdup(buff));
}
/**
 * adham_reverse_string - reverses str
 * @str : string
 * @len : length
 */

void adham_reverse_string(char *str, int len)
{
	char temp;
	int strt = 0;
	int en = len - 1;

	while (strt < en)
	{
		temp = str[strt];
		str[strt] = str[en];
		str[en] = temp;
		strt++;
		en--;
	}
}
/**
 * adham_printerr - prints  error
 * @nm : shell's name
 * @cmd : command
 * @i : number
 *
 */

void adham_printerr(char *nm, char *cmd, int i)
{
	char *ind, mg[] = ": not found\n";

	ind = adham_itoa(i);

	write(STDERR_FILENO, nm, adham_strlen(nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ind, adham_strlen(ind));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, adham_strlen(cmd));
	write(STDERR_FILENO, mg, adham_strlen(mg));

	free(ind);
}
