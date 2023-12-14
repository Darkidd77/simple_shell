#include "shell.h"

/**
 * _strcopy - copies a string
 * @d: the destination
 * @s: the source
 *
 * Return: pointer to destination
 */
char *_strcopy(char *d, char *s)
{
	int n = 0;

	if (d == src || s == 0)
		return (d);
	while (s[n])
	{
		d[n] = s[n];
		n++;
	}
	d[n] = 0;
	return (d);
}

/**
 * _strdpl - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdpl(const char *str)
{
	int leng = 0;
	char *r;

	if (str == NULL)
		return (NULL);
	while (*str++)
		leng++;
	r = malloc(sizeof(char) * (leng + 1));
	if (!r)
		return (NULL);
	for (leng++; leng--;)
		ret[leng] = *--str;
	return (r);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_putchar(str[n]);
		n++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(1, buf, n);
		n = 0;
	}
	if (ch != BUF_FLUSH)
		buf[n++] = ch;
	return (1);
}
