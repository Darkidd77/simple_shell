#include "shell.h"

/**
 * **strw - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @deli: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strw(char *str, char *deli)
{
	int x, y, v, z, nwords = 0;
	char **a;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!deli)
		deli = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], deli) && (is_delim(str[x + 1], deli) || !str[x + 1]))
			nwords++;

	if (nwords == 0)
		return (NULL);
	a = malloc((1 + nwords) * sizeof(char *));
	if (!a)
		return (NULL);
	for (x = 0, y = 0; y < nwords; y++)
	{
		while (is_delim(str[x], deli))
			x++;
		v = 0;
		while (!is_delim(str[x + v], deli) && str[x + v])
			k++;
		a[y] = malloc((v + 1) * sizeof(char));
		if (!a[y])
		{
			for (v = 0; v < y; v++)
				free(a[v]);
			free(a);
			return (NULL);
		}
		for (z = 0; z < v; z++)
			a[y][z] = str[x++];
		a[y][z] = 0;
	}
	a[y] = NULL;
	return (a);
}

/**
 * **strw2 - splits a string into words
 * @str: the input string
 * @deli: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strw2(char *str, char deli)
{
	int x, y, v, z, nwords = 0;
	char **a;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != deli && str[x + 1] == deli) ||
		    (str[x] != deli && !str[x + 1]) || str[x + 1] == deli)
			nwords++;
	if (nwords == 0)
		return (NULL);
	a = malloc((1 + nwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < nwords; y++)
	{
		while (str[x] == deli && str[x] != deli)
			x++;
		v = 0;
		while (str[x + v] != deli && str[x + v] && str[x + v] != deli)
			v++;
		a[y] = malloc((v + 1) * sizeof(char));
		if (!a[y])
		{
			for (v = 0; v < y; v++)
				free(s[v]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < v; z++)
			a[y][z] = str[x++];
		a[y][z] = 0;
	}
	a[y] = NULL;
	return (a);
}
