#include "shell.h"
/**
 * _strleng - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strleng(char *str)
{
	int x = 0;

	if (!str)
		return (0);

	while (*str++)
		x++;
	return (x);
}

/**
 * _strc - performs lexicogarphic comparison of two strangs.
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return: negative, positive, zero
 */
int _strc(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_w - checks if needle starts with haystack
 * @hystk: string to search
 * @ndl: the substring to find
 *
 * Return: address of next char of hystk or NULL
 */
char *starts_w(const char *hystk, const char *ndl)
{
	while (*ndl)
		if (*ndl++ != *hystk++)
			return (NULL);
	return ((char *)hystk);
}

/**
 * _strccat - concatenates two strings
 * @d: the destination buffer
 * @s: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strccat(char *d, char *s)
{
	char *r = d;

	while (*d)
		d++;
	while (*s)
		*d++ = *s++;
	*d = *s;
	return (r);
}
