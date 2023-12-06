#include "shell.h"

/**
 * readl - function to read the command line
 *
 * Return: command line
 */


char *readl(void)
{
	char *l = '\0';
	ssize_t n;
	size_t leng = 0;

	n = getline(&l, &leng, stdin);
	return (l);
}
