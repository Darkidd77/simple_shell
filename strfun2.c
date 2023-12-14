#include "shell.h"

/**
 **_strncopy - copies a string
 *@d: the destination string to be copied to
 *@s: the source string
 *@n: the number characters to be copied
 *Return: the concatenated string
 */
char *_strncopy(char *d, char *s, int n)
{
	int x, y;
	char *a = d;

	x = 0;
	while (s[x] != '\0' && x < n - 1)
	{
		d[x] = s[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (y < n)
		{
			d[y] = '\0';
			y++;
		}
	}
	return (a);
}

/**
 **_strnccat - concatenates two strings
 *@d: the first string
 *@s: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strnccat(char *d, char *s, int n)
{
	int x, y;
	char *a = d;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < n)
		d[x] = '\0';
	return (a);
}

/**
 **_strch - locates a character in a string
 *@str: the string to be parsed
 *@ch: the character to look for
 *Return: (a) a pointer to the memory area s
 */
char *_strch(char *str, char ch)
{
	do {
		if (*a == ch)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
