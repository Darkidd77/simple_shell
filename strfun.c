#include "shell.h"

char *_strdup(const char *str)
{
	char *ptr;
	int n, leng = 0;

	if (str == '\0')
		return ('\0');

	while (*str != '\0')
	{
		leng++;
		str++;
	}
	str = str - leng;
	ptr = malloc(sizeof(char) * (leng + 1));

	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= leng; i++)
		ptr[i] = str[i];
	return (ptr);
}

int _strcmp(char *s1, char *s2)
{
	int cmp;
	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{

